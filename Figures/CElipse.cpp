#include "CElipse.h"


CElipse::CElipse(Point P1, GfxInfo FigureGfxInfo): CFigure(FigureGfxInfo)
{   setType();
	ShiftPoints(P1);
	Center = P1;
	
}

void CElipse::Draw(Output* pOut) const{

	pOut->DrawEli(Center, FigGfxInfo, Selected);
}
bool CElipse::IsInside(int x, int y)
{
	//if the point in, it will return true
	return (x - Center.x) * (x - Center.x) / ((100.0) * (100)) +
		(y - Center.y) * (y - Center.y) / ((50.0) * (50)) <= 1;
}

void CElipse::ShiftPoints(Point& C)
{
	if(C.y - 50 < UI.ToolBarHeight + 1)
	{
		C.y = UI.ToolBarHeight + 51;
	}
	if(C.x - 100 < UI.ToolBarHeight + 1)
	{
		C.x = UI.ToolBarHeight + 101;
	}
	if(C.y + 50 > UI.height - UI.StatusBarHeight - 1)
	{
		C.y = UI.height - UI.StatusBarHeight - 51;
	}
}

void CElipse::SetCenter(int& x, int& y)
{   	
	Point Center;
	Center.x = x;
	Center.y = y;
	ShiftPoints(Center);
	this->Center = Center;
}
void CElipse::Save(ofstream &OutFile)
{
	OutFile<<"ELLIPSE    "<<ID<<"    "<<Center.x<<"    "<<Center.y<<"    "<<strDrawClr()<<"    "<<((FigGfxInfo.isFilled) ? strFillClr() : "NO_FILL")<<endl; 
	// 0 means NO_FILL
}
void CElipse::Load(ifstream &Infile){}
void CElipse::PrintInfo(Output* pOut)
{
	if(FigGfxInfo.isFilled == true)
		pOut->PrintMessage("Figure: "+strType()+"    Draw Color: "+strDrawClr()+"    Fill Color: "+strFillClr());
	else
        pOut->PrintMessage("Figure: "+strType()+"    Draw Color: "+strDrawClr()+"    No-Fill");
}

void CElipse::setType(){
Type = 5;
}

