#ifndef CLINE_H
#define CLINE_H

#include "CFigure.h"

class CLine :
	public CFigure
{
private:
	Point Corner1;
	Point Corner2;
public:
	CLine(Point , Point, GfxInfo FigureGfxInfo); //constructor for line 
	~CLine(void);
	virtual void Draw(Output* pOut) const; //draw function for line
};

#endif
