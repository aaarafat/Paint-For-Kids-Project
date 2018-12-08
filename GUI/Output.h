#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();		

	window* CreateWind(int, int, int , int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void Create2ndToolBar() const; //Creates the 2nd toolbar
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	void CreateColorBar() const;  //create the color bar
	void CreateReszieBar() const; //create the resize bar

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	void ClearToolBar() const; //Clears the toolbar
	void Clear2ndToolBar() const; //Clears the 2nd toolbar
	
	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a rectangle
	void DrawTri(Point P1, Point P2, Point P3,  GfxInfo TriGfxInfo, bool selected=false) const;
	void DrawL(Point P1, Point P2, GfxInfo LiGfxInfo, bool selected = false) const;
	void DrawEli(Point P1, GfxInfo EliGfxInfo, bool selected = false) const;
	void DrawRhom(Point P1, GfxInfo RhomGfxInfo, bool selected = false) const;


	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width

	string strDrawClr();
	string strFillClr();
	~Output();
};

#endif