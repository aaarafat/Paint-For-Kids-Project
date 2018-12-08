#pragma once
#include "CFigure.h"

class CRhombus : public CFigure
{
private:
	Point Center;
	float area(int x1, int y1, int x2, int y2, int x3, int y3);
public:
	CRhombus();
	CRhombus(Point, GfxInfo FigureGfxInfo);
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
