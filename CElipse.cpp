#include "CElipse.h"


CElipse::CElipse(Point P1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
Center = P1;
}

void CElipse::Draw(Output* pOut) const{

	pOut->DrawEli(Center, FigGfxInfo, Selected);
}

