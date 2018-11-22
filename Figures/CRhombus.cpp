#include "CRhombus.h"


CRhombus::CRhombus(Point C, GfxInfo RhomGfxInfo) : CFigure(RhomGfxInfo)
{
	Center = C;
}


void CRhombus::Draw(Output* pOut) const
{
	//Call Output::DrawRhom to draw a rectangle on the screen
	pOut->DrawRhom(Center, FigGfxInfo, Selected);
}

