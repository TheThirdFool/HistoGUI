
/*

	This is an example for HistoGUI usage.
	Compile with:
		g++ -o ex Example.cxx -lX11 

	The -lX11 is a compilation flag needed for the GUI.

*/

// First you must include the HistoGUI header file. (Also contains vector etc)
#include "HistoGUI.hpp"

// Program to run
int main(int argc, char ** argv){
/*
	// Data is stored in a vector
	std::vector< double > X; 
	std::vector< double > Y; 

	for(int i = -50; i < 50; i++){
		X.push_back(i);
		Y.push_back(-1.0 * i*i);		
	}

	// Create the HistoGUI object
	HistoGUI gui;
	gui.Help();

	// Fill with the data
	gui.Set2D(false);
	gui.SetData( X, Y );

	// Run the GUI	
	gui.Init();
	gui.Loop();

	// Close the GUI when it is closed
	gui.Close();
	
	return 0.0;
*/

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

	for(int i = 0; i < n_samples; i++){
		double x_val = scaleX * i + startX;
		X2.push_back(x_val);

		double y_val = scaleY * i + startY;
		Y2.push_back(y_val);		
	
		std::vector< double > temp; 
		for(int j = 0; j < n_samples; j++){
			y_val = scaleY * j + startY;

		//	printf("(%f, %f) = %f\n", x_val, y_val, x_val * y_val);
			temp.push_back(x_val * y_val);		
		}
		Z2.push_back(temp);		
	}
	// Data is X, Y = x, y coordinates of data, Z = nested (y long) vectors for each x coordinate.

	gui2.Set2D(true);
	gui2.SetData2D(X2,Y2,Z2);

	// Run the GUI	
	gui2.Init();
	gui2.Loop();

	// Close the GUI when it is closed
	gui2.Close();

	return 0;
}



