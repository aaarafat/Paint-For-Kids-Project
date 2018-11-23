#pragma once
#include "..\Figures\CFigure.h"
class CElipse : public CFigure
{
private:
	Point Center;	
	
public:
	CElipse(Point , GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	bool IsInside(int x, int y);
};

