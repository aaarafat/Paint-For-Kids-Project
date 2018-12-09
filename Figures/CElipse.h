#pragma once
#include "CFigure.h"
class CElipse : public CFigure
{
private:
	Point Center;	
	int r;
public:
	CElipse();
	CElipse(Point , GfxInfo FigureGfxInfo, int r = 100);
	virtual void Draw(Output* pOut) const;
	bool IsInside(int x, int y);
	virtual void SetCenter(int& x, int& y);   //change the figure's center
	virtual void ShiftPoints(Point& c);
	virtual void Save(ofstream &OutFile, ofstream& colors, ofstream& figures);
	void Load(ifstream &Infile);
	virtual void PrintInfo(Output* pOut);
	virtual void setType();
	virtual int getType();
	virtual void Resize(float frac, bool& flag);
};

