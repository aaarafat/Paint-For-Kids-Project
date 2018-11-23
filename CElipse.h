#pragma once
#include "f:\git project paint\project\figures\cfigure.h"
class CElipse : public CFigure
{
private:
	Point Center;	
	
public:
	CElipse(Point , GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
};

