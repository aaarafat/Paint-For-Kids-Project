#ifndef CLINE_H
#define CLINE_H

#include "CFigure.h"

class CLine :
	public CFigure
{
private:
	Point Point1;
	Point Point2;
	float area(int x1, int y1, int x2, int y2, int x3, int y3);
public:
	CLine(Point, Point, GfxInfo FigureGfxInfo); //constructor for line 
	virtual void Draw(Output* pOut) const; //draw function for line
	virtual bool IsInside(int x, int y);
	virtual void SetCenter(int& x, int& y);
	virtual void Save(ofstream &OutFile);
	void Load(ifstream &Infile);
	virtual void PrintInfo(Output* pOut);
	virtual void setType();
};

#endif
