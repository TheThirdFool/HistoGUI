

/*

	This is an example for HistoGUI fitting usage.
	Compile with:
		g++ -o fit Fitting.cxx -lX11

	The -lX11 is a compilation flag needed for the GUI.

*/

// First you must include the HistoGUI header file. (Also contains vector etc)
#include "HistoGUI.hpp"

// Using a random library to generate gaussian data.
#include <random>


// Define a subclass (derived class) from HistoGUI
class HistoGUI_Update : public HistoGUI {
	public:
	// We will be redefining Refresh, but extra functions can be added if needed.
	int Refresh();

	// Define gaussian generator here so can be used in refresh
	std::default_random_engine generator;
	std::normal_distribution<double> distribution;
	HistoGUI_Update(): distribution(160,24.5) {}

};

// Write a custom refresh function. This adds an extra 1000 samples. 
int HistoGUI_Update::Refresh(){
	for(int i = 0; i < 1000; i++){
    	double number = distribution(generator);
	    //if ((number>=-10.0)&&(number<10.0)) y[int((number + 10.0)*10)] += 1;
	    if ((number>=100.0)&&(number<300.0)) y[int((number - 100.0))] += 1;
	}
	return 1;
}


// Program to run
int main(int argc, char** argv){

	// Data is stored in a vector
	std::vector< double > X; 
	std::vector< double > Y; 

	// Define a histogram with 200 bins
	for(int i = 0; i < 200; i++){
		//X.push_back((i / 10.0)-10.0);
		X.push_back(i + 100.0);
		Y.push_back(0.0);		
	}

	// Create the HistoGUI object (HistoGUI_Update for custom refresh function)
	HistoGUI_Update gui;
	gui.Help();

	// Fill with gaussian data to start with
	for(int i = 0; i < 5000; i++){
    	double number = gui.distribution(gui.generator);
	    //if ((number>=-10.0)&&(number<10.0)) Y[int((number + 10.0)*10)] += 1;
	    if ((number>=100.0)&&(number<300.0)) Y[int((number - 100.0))] += 1;
	}

	// Set auto refresh with custom refresh rate of 100 ms
	// gui.SetAutoRefresh(true, 100);

	// Fill with the data
	gui.Set2D(false);
	gui.SetData( X, Y );

	// Set axis titles
	gui.SetAxisTitles((char*)"X",(char*)"Y");

	// Run the GUI	
	gui.Init();
	gui.Loop();

	// Close the GUI when it is closed
	gui.Close();
	
	return 0;
}



















