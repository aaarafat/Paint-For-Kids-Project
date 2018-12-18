#pragma once
#include "CFigure.h"
class CElipse : public CFigure
{
private:
	Point Center;	//The center point
	int r;          //radius
public:
	CElipse();
	CElipse(Point , GfxInfo FigureGfxInfo, int r = 100);
	virtual void Draw(Output* pOut) const;   //Draw function
	bool IsInside(int x, int y);             //Checks that the point is inside the elipse
	virtual void SetCenter(int& x, int& y);   //change the figure's center
	virtual void ShiftPoints(Point& c);       //Shift the center
 	virtual void Save(ofstream &OutFile, ofstream& colors, ofstream& figures);   //Save the elipse
	void Load(ifstream &Infile);   //Loads the elipse
	virtual void PrintInfo(Output* pOut);   //print the elipse info
	virtual void setType();      //Sets the type number
	virtual int getType();       //Gets the type number
	virtual void Resize(float frac, bool& flag);   //Resize the elipse
};

