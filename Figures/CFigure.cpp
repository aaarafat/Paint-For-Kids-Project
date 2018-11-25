#include "CFigure.h"
CFigure::CFigure(CFigure& F)
{
	static int i = 200;
	ID = i;
	Selected = F.Selected;
	FigGfxInfo = F.FigGfxInfo;
	DCLR = F.DCLR;
	FCLR = F.FCLR;
	Type = F.Type;
	i++;
}

CFigure::CFigure(GfxInfo FigureGfxInfo)
{
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	setDrawClr();
	if(FigGfxInfo.isFilled == true) setFillClr();
	Selected = false;
	static int i =1 ;
	ID = i;
	i++;
	atoi()
}

void CFigure::setDrawClr(){
	if(FigGfxInfo.DrawClr==BLACK){DCLR=1;}
	if(FigGfxInfo.DrawClr==WHITE){DCLR=2;}
	if(FigGfxInfo.DrawClr==RED){DCLR=3;}
	if(FigGfxInfo.DrawClr==GREEN){DCLR=4;}
	if(FigGfxInfo.DrawClr==BLUE){DCLR=5;}
}

void CFigure::setFillClr(){
	if(FigGfxInfo.FillClr==BLACK){FCLR=1;}
	if(FigGfxInfo.FillClr==WHITE){FCLR=2;}
	if(FigGfxInfo.FillClr==RED){FCLR=3;}
	if(FigGfxInfo.FillClr==GREEN){FCLR=4;}
	if(FigGfxInfo.FillClr==BLUE){FCLR=5;}
}

string CFigure::strDrawClr(){
if(DCLR==1) return "Black";
if(DCLR==2) return "White";
if(DCLR==3) return "Red";
if(DCLR==4) return "Green";
if(DCLR==5) return "Blue";
}

string CFigure::strFillClr(){
if(FCLR==1) return "Black";
if(FCLR==2) return "White";
if(FCLR==3) return "Red";
if(FCLR==4) return "Green";
if(FCLR==5) return "Blue";
}

string CFigure::strType(){
if(Type==1) return "Rectangle";
if(Type==2) return "Line";
if(Type==3) return "Triangle";
if(Type==4) return "Rhombus";
if(Type==5) return "Ellipse";
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; 
    setDrawClr();
}

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr;
	setFillClr();
}

color CFigure::GetDrawClr() const
{
	return FigGfxInfo.DrawClr;
}
