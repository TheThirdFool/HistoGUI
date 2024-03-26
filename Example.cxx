
/*

	This is an example for HistoGUI usage.
	Compile with:
		g++ -o ex Example.cxx -lX11 

	The -lX11 is a compilation flag needed for the GUI.

*/

// First you must include the HistoGUI header file. (Also contains vector etc)
#include "HistoGUI.hpp"


// Define a subclass (derived class) from HistoGUI
class HistoGUI_Update : public HistoGUI {
	public:
	// We will be redefining Refresh, but extra functions can be added if needed.
	int Refresh();
};

// Write a custom refresh function. This can read from a predefined file etc. 
int HistoGUI_Update::Refresh(){
	double xLast = x.back() + 1.0;

	// x & y are the two vectors in 1D
	x.push_back(xLast);
	y.push_back(xLast * xLast * xLast);
	printf("Custom refresh function\n");
	return 1;
}


// Program to run
int main(int argc, char ** argv){
	// Data is stored in a vector
	std::vector< double > X; 
	std::vector< double > Y; 

	for(int i = -50; i < 50; i++){
		X.push_back(i);
		Y.push_back(i*i*i);		
	}

	// Create the HistoGUI object (HistoGUI_Update for custom refresh function)
	HistoGUI_Update gui;
	gui.Help();

	// Fill with the data
	gui.Set2D(false);
	gui.SetData( X, Y );

	// Run the GUI	
	gui.Init();
	gui.Loop();

	// Close the GUI when it is closed
	gui.Close();
	
	// ==== or if 2D ====

	// Create the HistoGUI object
	HistoGUI gui2;
	gui2.Help();

	// Fill with the data
	std::vector< double > X2; 
	std::vector< double > Y2; 
	std::vector< std::vector< double > > Z2; 

	double startX = -50.0;
	double endX = 50.0;

	double startY = -50.0;
	double endY = 50.0;

	int n_samples = 1000;

	double scaleX = (endX - startX) / n_samples;
	double scaleY = (endY - startY) / n_samples;

	// The HistoGUI 2D structure is based off a 2D histogram. The X and Y axis can be 
	// thought of as defining the X and Y bins. With the Z 2D vector is the occupancy
	// of the bins.  

	for(int i = 0; i < n_samples; i++){
		double x_val = scaleX * i + startX;
		X2.push_back(x_val);

		double y_val = scaleY * i + startY;
		Y2.push_back(y_val);		
	
		std::vector< double > temp; 
		for(int j = 0; j < n_samples; j++){
			y_val = scaleY * j + startY;
			temp.push_back(x_val * y_val);		
		}
		Z2.push_back(temp);		
	}

	gui2.Set2D(true);
	gui2.SetData2D(X2,Y2,Z2);

	// Run the GUI	
	gui2.Init();
	gui2.Loop();

	// Close the GUI when it is closed
	gui2.Close();

	return 0;
}



