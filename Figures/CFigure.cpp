#include "CFigure.h"
CFigure::CFigure()
{
	Selected = false;
	FigGfxInfo.isFilled = false;
	IsCut= false;
}

CFigure::CFigure(CFigure& F)
{
	static int i = 200;
	ID = i;
	Selected = F.Selected;
	FigGfxInfo = F.FigGfxInfo;
	FigGfxInfo.isFilled = F.FigGfxInfo.isFilled;
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
	LastDClr = FigGfxInfo.DrawClr;
	LastFClr = FigGfxInfo.FillClr;
}

void CFigure::setDrawClr(){
	if(FigGfxInfo.DrawClr==BLACK){DCLR=1;}
	else if(FigGfxInfo.DrawClr==WHITE){DCLR=2;}
	else if(FigGfxInfo.DrawClr==RED){DCLR=3;}
	else if(FigGfxInfo.DrawClr==GREEN){DCLR=4;}
	else if(FigGfxInfo.DrawClr==BLUE){DCLR=5;}
	else if(LastDClr==BLACK){DCLR=1;}
	else if(LastDClr==WHITE){DCLR=2;}
	else if(LastDClr==RED){DCLR=3;}
	else if(LastDClr==GREEN){DCLR=4;}
	else if(LastDClr==BLUE){DCLR=5;}
}

void CFigure::setFillClr(){
	if(FigGfxInfo.FillClr==BLACK){FCLR=1;}
	else if(FigGfxInfo.FillClr==WHITE){FCLR=2;}
	else if(FigGfxInfo.FillClr==RED){FCLR=3;}
	else if(FigGfxInfo.FillClr==GREEN){FCLR=4;}
	else if(FigGfxInfo.FillClr==BLUE){FCLR=5;}
	else if(LastFClr==BLACK){FCLR=1;}
	else if(LastFClr==WHITE){FCLR=2;}
	else if(LastFClr==RED){FCLR=3;}
	else if(LastFClr==GREEN){FCLR=4;}
	else if(LastFClr==BLUE){FCLR=5;}
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
if(Type == 2) return strDrawClr();
return "NO_FILL";
}

string CFigure::strType(){
if(Type==1) return "RECTANGLE";
if(Type==2) return "LINE";
if(Type==3) return "TRIANGLE";
if(Type==4) return "RHOMBUS";
if(Type==5) return "ELLIPSE";
}

void CFigure::SetSelected(bool s)
{	
	Selected = s;
}

bool CFigure::IsSelected() const
{	return Selected; }

color CFigure::lClr(string dc)
{
if(dc=="Black") return BLACK;
if(dc=="White") return WHITE;
if(dc=="Red") return RED;
if(dc=="Green") return GREEN;
if(dc=="Blue") return BLUE;
}



void CFigure::ChngDrawClr(color Dclr)
{
	FigGfxInfo.DrawClr = Dclr; 
	//LastDClr = Dclr;
    setDrawClr();
}

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr;
	//LastFClr = Fclr;
	//wasFilled = true;
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