
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

	// Data is stored in a vector
	std::vector< double > X; 
	std::vector< double > Y; 

	for(int i = 0; i < 100; i++){
		X.push_back(i);
		Y.push_back(i*i);		
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


	// ==== or if 2D ====

	// Create the HistoGUI object
	HistoGUI gui2;
	gui2.Help();

	// Fill with the data
	std::vector< double > X2; 
	std::vector< double > Y2; 
	std::vector< std::vector< double > > Z2; 
	for(int i = 0; i < 100; i++){
		X2.push_back(i);
		Y2.push_back(i);		
	
		std::vector< double > temp; 
		for(int j = 0; j < 100; j++){
			temp.push_back(j*i);		
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



