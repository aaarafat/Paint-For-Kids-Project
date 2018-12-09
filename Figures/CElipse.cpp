#include "CElipse.h"
CElipse::CElipse()
{

}


CElipse::CElipse(Point P1, GfxInfo FigureGfxInfo, int r): CFigure(FigureGfxInfo)
{   
	this->r = r;
	setType();
	ShiftPoints(P1);
	Center = P1;
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
		C.y = UI.ToolBarHeight + r/2 + 1;
	}
	if(C.x - r < UI.ToolBarHeight + 1)
	{
		C.x = UI.ToolBarHeight + r + 1;
	}
	if (C.x + r > UI.width - 1)
	{
		C.x = UI.width - r - 15;
	}
	if(C.y + r/2 > UI.height - UI.StatusBarHeight - 1)
	{
		C.y = UI.height - UI.StatusBarHeight - r/2 + 1;
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
	OutFile<<"ELLIPSE    "<<ID<<"    "<<r<<"    "<<Center.x<<"    "<<Center.y<<"    "<<strDrawClr()<<"    "<<((FigGfxInfo.isFilled) ? strFillClr() : "NO_FILL")<<endl; 
	// 0 means NO_FILL
}
void CElipse::Load(ifstream &Infile)
{
	string dc,fc;
	int id, r;
	int x, y;
	
	Infile>>id>>r>>x>>y>>dc>>fc;
	this->r = r;
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
	frac = sqrt(frac);
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
	else if (Center.x + r > UI.width - 1)
	{
		r /= frac;
		flag = false;
	}
}