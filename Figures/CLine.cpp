#include "CLine.h"
CLine::CLine()
{

}


CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{   setType();
	FigGfxInfo.isFilled = false;
	Point1 = P1;
	Point2 = P2;
}

void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawL to draw a line on the screen
	pOut->DrawL(Point1, Point2, FigGfxInfo, Selected);
}

bool CLine::IsInside(int x, int y)
{
   float A = 2 * area (Point1.x, Point1.y - 6, Point1.x, Point1.y + 6, Point2.x , Point2.y - 6);
   
   float A1 = area (x, y, Point1.x, Point1.y + 6, Point2.x, Point2.y + 6); 
    
   float A2 = area (Point1.x, Point1.y + 6, x, y, Point1.x, Point1.y - 6); 
     
   float A3 = area (Point2.x, Point2.y + 6, x, y, Point2.x, Point2.y - 6); 
   
   float A4 = area (Point1.x, Point1.y - 6, x, y, Point2.x, Point2.y - 6); 
   /* Check if sum of A1, A2 and A3 and A4 is same as A */ 
   return (A == (A1 + A2 + A3 + A4)); 
}

float CLine::area(int x1, int y1, int x2, int y2, int x3, int y3)
{ 
	return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0); 
} 
void CLine::Save(ofstream &OutFile, ofstream& colors, ofstream& figures)
{
	figures<<"LINE"<<endl;
	colors<<"NO_FILL"<<endl;
	OutFile<<"LINE    "<<ID<<"    "<<Point1.x<<"    "<<Point1.y<<"    "<<"    "<<Point2.x<<"    "<<Point2.y<<"    "<<strDrawClr()<<"    "<<"NO_FILL"<<endl; 
}
void CLine::Load(ifstream &Infile)
{
	string dc,fc;
	int id;
	int x1, y1;
	int x2, y2;
	
	Infile>>id>>x1>>y1>>x2>>y2>>dc>>fc;
    ID =id;
	Point1.x = x1;
    Point1.y = y1;
	Point2.x = x2;
	Point2.y = y2;
	ChngDrawClr(lClr(dc));
	LastDClr = lClr(dc);
	LastFClr = lClr(fc);
}
void CLine::SetCenter(int& x, int& y)
{
	Point C;
	C.x = (Point1.x + Point2.x)/2;
	C.y = (Point1.y + Point2.y)/2;
	Point1.x += x - C.x;
	Point2.x += x - C.x;
	Point1.y += y - C.y;
	Point2.y += y - C.y;
	if(Point1.y < UI.ToolBarHeight + 1)
	{
		y = y + (UI.ToolBarHeight + 1 - Point1.y);
		SetCenter(x, y);
	}
	if(Point2.y < UI.ToolBarHeight + 1)
	{
		y = y + (UI.ToolBarHeight + 1 - Point2.y);
		SetCenter(x, y);
	}
	if(Point1.x < UI.ToolBarHeight + 1)
	{
		x = x + (UI.ToolBarHeight + 1 - Point1.x);
		SetCenter(x, y);
	}
	if(Point2.x < UI.ToolBarHeight + 1)
	{
		x = x + (UI.ToolBarHeight + 1 - Point2.x);
		SetCenter(x, y);
	}
	if(Point1.y > UI.height - UI.StatusBarHeight - 1)
	{
		y = y - (Point1.y - UI.height + UI.StatusBarHeight + 1);
		SetCenter(x, y);
	}
	if(Point2.y > UI.height - UI.StatusBarHeight - 1)
	{
		y = y - (Point2.y - UI.height + UI.StatusBarHeight + 1);
		SetCenter(x, y);
	}
}
void CLine::PrintInfo(Output* pOut){
pOut->PrintMessage("Figure: "+strType()+"    Draw Color: "+strDrawClr());

}
void CLine::setType(){
Type = 2;
}