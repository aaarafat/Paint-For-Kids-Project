#pragma once
#include "CFigure.h"

class CRhombus : public CFigure
{
private:
	Point Center;   //Rhombus center
	float area(int x1, int y1, int x2, int y2, int x3, int y3);  //Gets the Rhombus area
	int r;   //Radius
public:
	CRhombus();
	CRhombus(Point, GfxInfo FigureGfxInfo, int r = 100);
	virtual void Draw(Output* pOut) const;   //Draw the rhombus
	bool IsInside(int x, int y);   //Checks that the point is inside the rhombus
	virtual void SetCenter(int& x, int& y);   //change the figure's center
	virtual void ShiftPoints(Point& c);   //shifts the rhombus
	virtual void Save(ofstream &OutFile, ofstream& colors, ofstream& figures);   //save the rhombus
	void Load(ifstream &Infile);   //load the rhombus
	virtual void PrintInfo(Output* pOut);   //print the rhombus info
	virtual void setType();   //sets the figure type
	virtual int getType();    //gets the figure type
	virtual void Resize(float frac, bool& flag);   //Resizes the rhombus
};
