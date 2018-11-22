#pragma once
#include "CFigure.h"

class CRhombus : public CFigure
{
private:
	Point Center;
public:
	CRhombus(Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
};
