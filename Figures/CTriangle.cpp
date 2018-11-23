#include "CTriangle.h"


CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	ID = counter;
	counter += 1000;
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}
	

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTri to draw a triangle on the screen	
	pOut->DrawTri(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}
bool CTriangle::IsInside(int x, int y)
{
   float A = area (Corner1.x, Corner1.y, Corner2.x, Corner2.y, Corner3.x, Corner3.y); 
   
   float A1 = area (x, y, Corner2.x, Corner2.y, Corner3.x, Corner3.y); 
    
   float A2 = area (Corner1.x, Corner1.y, x, y, Corner3.x, Corner3.y); 
     
   float A3 = area (Corner1.x, Corner1.y, Corner2.x, Corner2.y, x, y); 
    
   /* Check if sum of A1, A2 and A3 is same as A */ 
   return (A == A1 + A2 + A3); 
}
float CTriangle::area(int x1, int y1, int x2, int y2, int x3, int y3)
{ 
	return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0); 
} 
void CTriangle::Save(ofstream &OutFile, string filename)
{
	//OutFile.open(filename);
	//if(FigGfxInfo.
	//OutFile<<"ELLIPSE\t"<<counter<<"\t"<<Center.x<<"\t"<<Center.y<<FigGfxInfo.DrawClr<<"\t"<<((FigGfxInfo.isFilled) ? FigGfxInfo.FillClr : 0)<<endl; 
	// 0 means NO_FILL
}
