#include "CLine.h"


CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}


CLine::~CLine(void)
{
}

void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawL to draw a line on the screen	
	pOut->DrawL(Corner1, Corner2, FigGfxInfo, Selected);
}