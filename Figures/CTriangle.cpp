#include "CTriangle.h"
CTriangle::CTriangle()
{

}


CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{   setType();
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


void CTriangle::SetCenter(int& x, int& y)
{
	Point C; //the center of the triangle
	C.x = (Corner1.x+Corner2.x+Corner3.x)/3;
	C.y = (Corner1.y+Corner2.y+Corner3.y)/3;
	if (x > C.x)
	{
		Corner1.x += x - C.x;
		Corner2.x += x - C.x;
		Corner3.x += x - C.x;
	}
	else
	{
		Corner1.x -= C.x - x;
		Corner2.x -= C.x - x;
		Corner3.x -= C.x - x;
	}
	if (y > C.y )
	{
		Corner1.y += y - C.y;
		Corner2.y += y - C.y;
		Corner3.y += y - C.y;
	}
	else
	{
		Corner1.y -= C.y - y;
		Corner2.y -= C.y - y;
		Corner3.y -= C.y - y;
	}
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
	if(Corner3.y < UI.ToolBarHeight + 1)
	{
		y = y + (UI.ToolBarHeight + 1 - Corner3.y);
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
	if(Corner3.x < UI.ToolBarHeight + 1)
	{
		x = x + (UI.ToolBarHeight + 1 - Corner3.x);
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
	if(Corner3.y > UI.height - UI.StatusBarHeight - 1)
	{
		y = y - (Corner3.y - UI.height + UI.StatusBarHeight + 1);
		SetCenter(x, y);
	}
}


void CTriangle::Save(ofstream &OutFile)
{
	OutFile<<"TRIANGLE    "<<ID<<"    "<<Corner1.x<<"    "<<Corner1.y<<"    "<<"    "<<Corner2.x<<"    "<<Corner2.y<<"    "<<Corner3.x<<"    "<<Corner3.y<<"    "<<strDrawClr()<<"    "<<((FigGfxInfo.isFilled) ? strFillClr() : "NO_FILL")<<endl; 
}
void CTriangle::Load(ifstream &Infile){}
void CTriangle::PrintInfo(Output* pOut){
	if(FigGfxInfo.isFilled == true)
		pOut->PrintMessage("Figure: "+strType()+"    Draw Color: "+strDrawClr()+"    Fill Color: "+strFillClr());
	else
        pOut->PrintMessage("Figure: "+strType()+"    Draw Color: "+strDrawClr()+"    No-Fill");
}
void CTriangle::setType(){
Type = 3;
}


