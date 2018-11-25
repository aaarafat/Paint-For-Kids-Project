#pragma once
#include "CFigure.h"
class CElipse : public CFigure
{
private:
	Point Center;	
	
public:
	CElipse(Point , GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	bool IsInside(int x, int y);
	virtual void SetCenter(int& x, int& y);   //change the figure's center
	virtual void ShiftPoints(Point& c);
	virtual void Save(ofstream &OutFile);
	virtual void PrintInfo(Output* pOut);
	virtual void setType();
};

