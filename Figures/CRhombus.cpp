#include "CRhombus.h"

CRhombus::CRhombus()
{

}

CRhombus::CRhombus(Point C, GfxInfo RhomGfxInfo) : CFigure(RhomGfxInfo)
{   setType();
	ShiftPoints(C);
	Center = C;
}


void CRhombus::Draw(Output* pOut) const
{
	//Call Output::DrawRhom to draw a rectangle on the screen
	pOut->DrawRhom(Center, FigGfxInfo, Selected);
}
bool CRhombus::IsInside(int x, int y)
{
   float A = 2 * area (Center.x - 50, Center.y, Center.x + 50, Center.y, Center.x, Center.y + 100);
   
   float A1 = area (x, y, Center.x + 50, Center.y, Center.x, Center.y + 100); 
    
   float A2 = area (Center.x - 50, Center.y, x, y, Center.x, Center.y + 100); 
     
   float A3 = area (Center.x - 50, Center.y, Center.x, Center.y - 100, x, y); 
   
   float A4 = area (Center.x + 50, Center.y, Center.x, Center.y - 100, x, y);
   /* Check if sum of A1, A2 and A3 and A4 is same as A */ 
   return (A == (A1 + A2 + A3 + A4)); 
}
float CRhombus::area(int x1, int y1, int x2, int y2, int x3, int y3)
{ 
	return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0); 
} 

void CRhombus::ShiftPoints(Point& C)
{
	if(C.y - 100 < UI.ToolBarHeight + 1)
	{
		C.y = UI.ToolBarHeight + 101;
	}
	if(C.x - 50 < UI.ToolBarHeight + 1)
	{
		C.x = UI.ToolBarHeight + 51;
	}
	if(C.y + 100 > UI.height - UI.StatusBarHeight - 1)
	{
		C.y = UI.height - UI.StatusBarHeight - 101;
	}
}


void CRhombus::SetCenter(int& x, int& y)
{   	
	Point C;
	C.x = x;
	C.y = y;
	ShiftPoints(C);
	this->Center = C;
}
void CRhombus::Save(ofstream &OutFile, ofstream& colors, ofstream& figures)
{
	figures<<"RHOMBUS"<<endl;
	colors<<((FigGfxInfo.isFilled) ? strFillClr() : "NO_FILL")<<endl;
	OutFile<<"RHOMBUS    "<<ID<<"    "<<Center.x<<"    "<<Center.y<<"    "<<strDrawClr()<<"    "<<((FigGfxInfo.isFilled) ? strFillClr() : "NO_FILL")<<endl; 
}
void CRhombus::Load(ifstream &Infile)
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
void CRhombus::PrintInfo(Output* pOut)
{
	if(FigGfxInfo.isFilled == true)
		pOut->PrintMessage("Figure: "+strType()+"    Draw Color: "+strDrawClr()+"    Fill Color: "+strFillClr());
	else
        pOut->PrintMessage("Figure: "+strType()+"    Draw Color: "+strDrawClr()+"    No-Fill");
}
void CRhombus::setType(){
Type = 4;
}