#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include <fstream>

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	int DCLR;
	int FCLR;
	int Type;
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	virtual bool IsInside(int x, int y) = 0;
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	color GetDrawClr() const;       //gets the figure's drawing color
	virtual void SetCenter(int& x, int& y)= 0;   //change the figure's center
	void setDrawClr() ; // sets an integer for each Draw Color
	void setFillClr() ; // sets an integer for each Fill Color
	virtual void setType() = 0;     // sets the type of the Figure
	string strDrawClr() ;  // returns Draw Color as a string 
	string strFillClr() ;  // returns Fill Color as a string 
	string strType();      // returns Type as a string
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	virtual void Save(ofstream &OutFile, string filename) = 0;	//Save the figure parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif