#include <X11/Xlib.h>
#include <X11/X.h>
#include <X11/Xutil.h>
#include <X11/XKBlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <cmath> 
#include <chrono>
#include <thread>
	
//#include "HistoGUI_Library.cpp"

#ifndef HISTOGUI
#define HISTOGUI

class HistoGUI{


	public:

	HistoGUI(){

		auto_refresh = false;	
		refresh_time = 1000; // miliseconds
		pi = 3.14159265358979323846;
		sqrt2Pi = 2.50662827463; 
		xAxisTitle[0] = '\0';
		yAxisTitle[0] = '\0';
		inProjection  = false;
	}

	Display * disp;
	Window    wind;
	Window    wind_overlay;
	XEvent    evt;
	int       screen;

	XColor xcolour;
	XColor xcolour_red;
	XColor xcolour_veryred;
	Colormap cmap;

	XColor PixelColour[20];

	std::vector<double> x;
	std::vector<double> y;
	std::vector< std::vector<double> > z;

	std::vector<double> xProj;
	std::vector<double> yProj;

	double max_x;
	double min_x;
	double max_y;
	double min_y;

	double pos_x;
	double pos_y;
	double pos_z;
	double new_pos_x;
	double new_pos_y;
	double bw_x;
	double bw_y;


	unsigned int width;  
	unsigned int height;  
	double window_width;
    double window_height;
	double width_scale; 
	double x_offset;
	double height_scale;
	double y_offset;
	bool Draw2D_On;
	bool inProjection;
	double scaleZ;
	bool drawLog;
	bool auto_refresh;
	long refresh_time;
	char yAxisTitle[64];
	char xAxisTitle[64];

	double FitEdgeLo;
	double FitEdgeHi;
	double oldEdge;
	bool   edgeSet;
	int nIterations;
	double fitParams[3];
	double pi;
	double sqrt2Pi; 
	int startingIndex;
	int endingIndex;
	bool funcDrawn;
	bool isZoomed;

	int nBinsX;
	double lowBinX;
	double highBinX;
	double incX;
	int nBinsY;
	double lowBinY;
	double highBinY;
	double incY;


	double old_xl, old_xh, old_yl, old_yh;
	double old_mouse_x, old_mouse_y;

	int Init();
	int SetData(std::vector<double> a, std::vector<double>b);
	int SetData(std::vector<double> a, std::vector<float>b);
	int Loop();	
	void Close(){ printf("Closing now!\n"); XCloseDisplay(disp); }
	int DrawData(double x_low_win, double y_low_win, double x_hi_win, double y_hi_win);
	virtual int DrawCrosshairs(int mouse_x, int mouse_y);
	int Zoom(int mouse_x, int mouse_y);
	int virtual Refresh();

	int SetData2D(std::vector<double> a, std::vector<double> b, std::vector< std::vector<double> > c);
	int DrawData2D(double x_low_win, double y_low_win, double x_hi_win, double y_hi_win);
	
	bool Set2D( bool a ){ Draw2D_On = a; return a;}
	long SetAutoRefresh( bool a, long milisec ){ auto_refresh = a; refresh_time = milisec; return milisec;}

	int SetFitEdge(int mouse_x);
	int SetFitEdgeY(int mouse_y);
	int Fit();	
	int DrawGaus();
	double Gaus(double inX);
	double DiffGaus_Mean(double inX);
	double DiffGaus_Sigma(double inX);
	double DiffGaus_Scale(double inX);
	double SelectDiffGaus(int index, double inX);
	int DrawMaximum();
	void ProjectX();
	void ProjectY();
	void SwapProj();

	void MakeHist1D(int nBins, double lowBin, double highBin);
	void MakeHist2D(int nBins_X, double lowBin_X, double highBin_X, int nBins_Y, double lowBin_Y, double highBin_Y);
	void Fill(double val);
	void Fill(double valX, double valY);
	

	void ClearData();

	int Help();
	int HelpCode();
	int ReturnViridis(int i, int j);

	int SetAxisTitles(char* xAxis, char* yAxis){
		snprintf(yAxisTitle, 64, "%s", yAxis);
		snprintf(xAxisTitle, 64, "%s", xAxis);	
		return 1;
	}

};

#endif


#include "HistoGUI_Library.cpp"
