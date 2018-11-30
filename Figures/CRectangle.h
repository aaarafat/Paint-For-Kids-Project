#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle();
	bool IsInside(int x, int y);
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual void SetCenter(int& x, int& y);   //change the figure's center
	virtual void Save(ofstream &OutFile);
	void Load(ifstream &Infile);
	virtual void PrintInfo(Output* pOut);
	virtual void setType();
};

#endif