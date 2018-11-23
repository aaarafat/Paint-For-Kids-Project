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
<<<<<<< HEAD

void CRectangle::SetCenter(Point Center)
{
	Point C;
	C.x = (Corner1.x + Corner2.x)/2;
	C.y = (Corner1.y + Corner2.y)/2;
	Corner1.x += Center.x - Corner1.x;
	Corner2.x += Center.x - Corner2.x;
	Corner1.y += Center.y - Corner1.y;
	Corner2.y += Center.y - Corner2.y;
}

=======
void CRectangle::Save(ofstream &OutFile, string filename)
{
	//OutFile.open(filename);
	//if(FigGfxInfo.
	//OutFile<<"ELLIPSE\t"<<counter<<"\t"<<Center.x<<"\t"<<Center.y<<FigGfxInfo.DrawClr<<"\t"<<((FigGfxInfo.isFilled) ? FigGfxInfo.FillClr : 0)<<endl; 
	// 0 means NO_FILL
}
>>>>>>> 048db81ab61d8e51dad859f041d42eaa3ecfee5a
