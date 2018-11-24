#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CRectangle::IsInside(int x, int y)
{
	int x1, y1, x2, y2;
	if(Corner1.x > Corner2.x)
	{
		x1 = Corner1.x;
		x2 = Corner2.x;
	}
	else
	{
		x2 = Corner1.x;
		x1 = Corner2.x;
	}
	if(Corner1.y > Corner2.y)
	{
		y1 = Corner1.y;
		y2 = Corner2.y;
	}
	else
	{
		y2 = Corner1.y;
		y1 = Corner2.y;
	}
	return (x <= x1 && x >= x2 && y <= y1 && y >= y2);
}

void CRectangle::SetCenter(int& x, int& y)
{
	Point C;
	C.x = (Corner1.x + Corner2.x)/2;
	C.y = (Corner1.y + Corner2.y)/2;
	Corner1.x += x - C.x;
	Corner2.x += x - C.x;
	Corner1.y += y - C.y;
	Corner2.y += y - C.y;
	if(Corner1.y < UI.ToolBarHeight + 1)
	{
		y = y + (UI.ToolBarHeight + 1 - Corner1.y);
		SetCenter(x, y);
	}
	if(Corner2.y < UI.ToolBarHeight + 1)
	{
		y = y + (UI.ToolBarHeight + 1 - Corner2.y);
		SetCenter(x, y);
	}
	if(Corner1.x < UI.ToolBarHeight + 1)
	{
		x = x + (UI.ToolBarHeight + 1 - Corner1.x);
		SetCenter(x, y);
	}
	if(Corner2.x < UI.ToolBarHeight + 1)
	{
		x = x + (UI.ToolBarHeight + 1 - Corner2.x);
		SetCenter(x, y);
	}
	if(Corner1.y > UI.height - UI.StatusBarHeight - 1)
	{
		y = y - (Corner1.y - UI.height + UI.StatusBarHeight + 1);
		SetCenter(x, y);
	}
	if(Corner2.y > UI.height - UI.StatusBarHeight - 1)
	{
		y = y - (Corner2.y - UI.height + UI.StatusBarHeight + 1);
		SetCenter(x, y);
	}

}

void CRectangle::Save(ofstream &OutFile, string filename)
{
	//OutFile.open(filename);
	//if(FigGfxInfo.
	//OutFile<<"ELLIPSE\t"<<counter<<"\t"<<Center.x<<"\t"<<Center.y<<FigGfxInfo.DrawClr<<"\t"<<((FigGfxInfo.isFilled) ? FigGfxInfo.FillClr : 0)<<endl; 
	// 0 means NO_FILL
}
void CRectangle::PrintInfo(Output* pOut){
pOut->PrintMessage(strDrawClr()+" "+strFillClr());
}

