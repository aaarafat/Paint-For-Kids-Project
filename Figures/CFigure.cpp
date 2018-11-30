#include "CFigure.h"
CFigure::CFigure()
{
	Selected = false;
	FigGfxInfo.isFilled = true;
}

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
	wasFilled = F.wasFilled;
	LastDClr = F.LastDClr;
	LastFClr = F.LastFClr;
	IsCut = F.IsCut;
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
	IsCut = false;
	wasFilled = FigGfxInfo.isFilled;
}

void CFigure::setDrawClr(){
	if(FigGfxInfo.DrawClr==BLACK){DCLR=1;}
	if(FigGfxInfo.DrawClr==WHITE){DCLR=2;}
	if(FigGfxInfo.DrawClr==RED){DCLR=3;}
	if(FigGfxInfo.DrawClr==GREEN){DCLR=4;}
	if(FigGfxInfo.DrawClr==BLUE){DCLR=5;}
	if(LastDClr==BLACK){DCLR=1;}
	if(LastDClr==WHITE){DCLR=2;}
	if(LastDClr==RED){DCLR=3;}
	if(LastDClr==GREEN){DCLR=4;}
	if(LastDClr==BLUE){DCLR=5;}
}

void CFigure::setFillClr(){
	if(FigGfxInfo.FillClr==BLACK){FCLR=1;}
	if(FigGfxInfo.FillClr==WHITE){FCLR=2;}
	if(FigGfxInfo.FillClr==RED){FCLR=3;}
	if(FigGfxInfo.FillClr==GREEN){FCLR=4;}
	if(FigGfxInfo.FillClr==BLUE){FCLR=5;}
	if(LastDClr==BLACK){FCLR=1;}
	if(LastDClr==WHITE){FCLR=2;}
	if(LastDClr==RED){FCLR=3;}
	if(LastDClr==GREEN){FCLR=4;}
	if(LastDClr==BLUE){FCLR=5;}
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

color CFigure::GetFillClr() const
{
	return FigGfxInfo.FillClr;
}

bool CFigure::isFill() const
{
	return FigGfxInfo.isFilled;
}

void CFigure::ChngToNonFill()
{
	FigGfxInfo.isFilled = false;
}

void CFigure::Cut(bool c)
{
	IsCut = c;
	if (c)
	{
		wasFilled = FigGfxInfo.isFilled;
		LastDClr = FigGfxInfo.DrawClr;
		LastFClr = FigGfxInfo.FillClr;
		ChngFillClr(GREY);
		ChngDrawClr(GREY);
	}
	else
	{
		ChngDrawClr(LastDClr);
		FigGfxInfo.FillClr = LastFClr;
		FigGfxInfo.isFilled = wasFilled;
		setFillClr();
	}
}

bool CFigure::isCut() const
{
	return IsCut;
}