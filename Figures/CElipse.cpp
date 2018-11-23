#include "CElipse.h"


CElipse::CElipse(Point P1, GfxInfo FigureGfxInfo): CFigure(FigureGfxInfo)
{
	ID = counter;
	counter += 1000;
	if(P1.y - 50 < UI.ToolBarHeight + 1)
	{
		P1.y = UI.ToolBarHeight + 51;
	}
	if(P1.x - 100 < UI.ToolBarHeight + 1)
	{
		P1.x = UI.ToolBarHeight + 101;
	}
	if(P1.y + 50 > UI.height - UI.StatusBarHeight - 1)
	{
		P1.y = UI.height - UI.StatusBarHeight - 51;
	}
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
<<<<<<< HEAD
void CElipse::SetCenter(Point Center)
{
	this->Center = Center;
=======
void CElipse::Save(ofstream &OutFile, string filename)
{
	//OutFile.open(filename);
	//if(FigGfxInfo.
	//OutFile<<"ELLIPSE\t"<<counter<<"\t"<<Center.x<<"\t"<<Center.y<<FigGfxInfo.DrawClr<<"\t"<<((FigGfxInfo.isFilled) ? FigGfxInfo.FillClr : 0)<<endl; 
	// 0 means NO_FILL
>>>>>>> 048db81ab61d8e51dad859f041d42eaa3ecfee5a
}

