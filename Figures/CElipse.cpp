#include "CElipse.h"
CElipse::CElipse()
{

}


CElipse::CElipse(Point P1, GfxInfo FigureGfxInfo): CFigure(FigureGfxInfo)
{   
	setType();
	ShiftPoints(P1);
	Center = P1;
	r = 100;
}

void CElipse::Draw(Output* pOut) const{

	pOut->DrawEli(Center, FigGfxInfo, r,Selected);
}
bool CElipse::IsInside(int x, int y)
{
	//if the point in, it will return true
	return (x - Center.x) * (x - Center.x) / ((r * 1.0) * (r)) +
		(y - Center.y) * (y - Center.y) / ((r/2 * 1.0) * (r/2)) <= 1;
}

void CElipse::ShiftPoints(Point& C)
{
	if(C.y - r/2 < UI.ToolBarHeight + 1)
	{
		C.y = UI.ToolBarHeight + 51;
	}
	if(C.x - r < UI.ToolBarHeight + 1)
	{
		C.x = UI.ToolBarHeight + 101;
	}
	if(C.y + r/2 > UI.height - UI.StatusBarHeight - 1)
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
void CElipse::Save(ofstream &OutFile, ofstream& colors, ofstream& figures)
{
	figures<<"ELLIPSE"<<endl;
	colors<<((FigGfxInfo.isFilled) ? strFillClr() : "NO_FILL")<<endl;
	OutFile<<"ELLIPSE    "<<ID<<"    "<<Center.x<<"    "<<Center.y<<"    "<<strDrawClr()<<"    "<<((FigGfxInfo.isFilled) ? strFillClr() : "NO_FILL")<<endl; 
	// 0 means NO_FILL
}
void CElipse::Load(ifstream &Infile)
{
	string dc,fc;
	int id;
	int x, y;
	
	Infile>>id>>x>>y>>dc>>fc;
    ID =id;
	Center.x = x;
    Center.y = y;
	ChngDrawClr(lClr(dc));
	if(fc!="NO_FILL") ChngFillClr(lClr(fc));
	LastDClr = lClr(dc);
	LastFClr = lClr(fc);
}
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

int CElipse::getType(){
return Type;
}

void CElipse::Resize(float frac, bool& flag)
{
	r *= frac;
	if(Center.y - r/2 < UI.ToolBarHeight + 1)
	{
		r /= frac;
		flag = false;
	}
	else if(Center.x - r < UI.ToolBarHeight + 1)
	{
		r /= frac;
		flag = false;
	}
	else if(Center.y + r/2 > UI.height - UI.StatusBarHeight - 1)
	{
		r /= frac;
		flag = false;
	}
}