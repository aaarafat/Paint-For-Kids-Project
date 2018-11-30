#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_LINE,		//Draw Line
	DRAW_RECT,		//Draw Rectangle
	DRAW_TRI,		//Draw Triangle
	DRAW_RHOMBUS,		//Draw Rhombus
	DRAW_ELLIPSE,		//Draw Ellipse
	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR,	//Change the filling color
	SELECT,			//Select a figure(s)
    COPY,           //Copy a figure(s)
	CUT,            //Cut a figure(s)
	PASTE,          //Paste a figure(s)
	DEL,			//Delete a figure(s)
	SAVE,			//Save the whole graph to a file
	SAVE_BY_TYPE,	//Save the all the figures that have a specific type
	LOAD,			//Load a graph from a file
	EXIT,			//Exit the application
	CHOOSE_BYTYPE,  //Choose by type in play mode
	CHOOSE_BYCOLOR, //Choose by color in play mode
	PLAYING_AREA,   //A click on the playing area 
	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar
	CLR_BLACK_C,
	CLR_WHITE_C,
	CLR_RED_C,
	CLR_GREEN_C,
	CLR_BLUE_C,
	

	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY			//Switch interface to Play mode

	///TODO: Add more action types (if needed)
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};
/*enum FClr{
	BLACK,
	WHITE,
	RED,
	GREEN,
	BLUE,

	COUNT,
};
enum DClr{
	BLACK,
	WHITE,
	RED,
	GREEN,
	BLUE,

	COUNT,
};

enum FType{
RECT,
LINE,
TRI,
RHOM,
ELIPSE,

COUNT,

};*/

#endif