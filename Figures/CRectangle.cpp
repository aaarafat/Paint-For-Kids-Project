#include "CRectangle.h"
CRectangle::CRectangle()
{

}

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{   setType();
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

void CRectangle::Save(ofstream &OutFile, ofstream& colors, ofstream& figures)
{
	figures<<"RECTANGLE"<<endl;
	colors<<((FigGfxInfo.isFilled) ? strFillClr() : "NO_FILL")<<endl;
	OutFile<<"RECTANGLE    "<<ID<<"    "<<Corner1.x<<"    "<<Corner1.y<<"    "<<Corner2.x<<"    "<<Corner2.y<<"    "<<strDrawClr()<<"    "<<((FigGfxInfo.isFilled) ? strFillClr() : "NO_FILL")<<endl; 
}
void CRectangle::Load(ifstream &Infile)
{
	string dc,fc;
	int id;
	int x1, y1;
	int x2, y2;
	
	Infile>>id>>x1>>y1>>x2>>y2>>dc>>fc;
    ID =id;
	Corner1.x = x1;
    Corner1.y = y1;
	Corner2.x = x2;
	Corner2.y = y2;
	ChngDrawClr(lClr(dc));
	if(fc!="NO_FILL") ChngFillClr(lClr(fc));
	LastDClr = lClr(dc);
	LastFClr = lClr(fc);
}
void CRectangle::PrintInfo(Output* pOut){
	if(FigGfxInfo.isFilled == true)
		pOut->PrintMessage("Figure: "+strType()+"    Draw Color: "+strDrawClr()+"    Fill Color: "+strFillClr());
	else
        pOut->PrintMessage("Figure: "+strType()+"    Draw Color: "+strDrawClr()+"    No-Fill");
}
void CRectangle::setType(){
Type = 1;
}

int CRectangle::getType(){
return Type;
}

void CRectangle::Resize(float frac, bool& flag)
{
	frac = sqrt(frac);
	Point Center;
	Center.x = (Corner1.x + Corner2.x)/2;
	Center.y = (Corner1.y + Corner2.y)/2;
	Point DsFromCenter;
	Point Corner3,Corner4;
	DsFromCenter.x = Center.x - Corner1.x;
	DsFromCenter.y = Center.y - Corner1.y;
	Corner1.x = Center.x + (DsFromCenter.x * sqrt(frac));
	Corner2.x = Center.x - (DsFromCenter.x * sqrt(frac));
	Corner1.y = Center.y + (DsFromCenter.y * sqrt(frac));
	Corner2.y = Center.y - (DsFromCenter.y * sqrt(frac));
	Corner3.x = Center.x + (DsFromCenter.x * sqrt(frac));
	Corner4.x = Center.x + (DsFromCenter.x * sqrt(frac));
	Corner3.y = Center.y - (DsFromCenter.y * sqrt(frac));
	Corner4.y = Center.y - (DsFromCenter.y * sqrt(frac));
	if (Corner1.x < UI.ToolBarHeight + 1 || Corner2.x < UI.ToolBarHeight + 1 ||
		Corner1.x > UI.width || Corner2.x > UI.width || 
		Corner3.x < UI.ToolBarHeight + 1 || Corner4.x < UI.ToolBarHeight + 1 ||
		Corner3.x > UI.width || Corner4.x > UI.width)
	{
		Corner1.x = Center.x + (DsFromCenter.x);
		Corner2.x = Center.x - (DsFromCenter.x);
		Corner1.y = Center.y + (DsFromCenter.y);
		Corner2.y = Center.y - (DsFromCenter.y);
		flag = false;
	}
	if (Corner1.y < UI.ToolBarHeight + 1 || Corner2.y < UI.ToolBarHeight + 1 ||
		Corner1.y > UI.height - UI.StatusBarHeight - 1 ||
		Corner2.y > UI.height - UI.StatusBarHeight - 1 ||
		Corner3.y < UI.ToolBarHeight + 1 || Corner4.y < UI.ToolBarHeight + 1 ||
		Corner3.y > UI.height - UI.StatusBarHeight - 1 ||
		Corner4.y > UI.height - UI.StatusBarHeight - 1)
	{
		Corner1.x = Center.x + (DsFromCenter.x);
		Corner2.x = Center.x - (DsFromCenter.x);
		Corner1.y = Center.y + (DsFromCenter.y);
		Corner2.y = Center.y - (DsFromCenter.y);
		flag = false;
	}
}