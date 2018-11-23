#include "CLine.h"


CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Point1 = P1;
	Point2 = P2;
}


CLine::~CLine(void)
{
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
