#pragma once
#include "cfigure.h"
class CTriangle :
	public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	Point Corner3;
public:
	CTriangle(Point , Point,Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
};

