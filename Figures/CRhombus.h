#pragma once
#include "CFigure.h"

class CRhombus : public CFigure
{
private:
	Point Center;
	float area(int x1, int y1, int x2, int y2, int x3, int y3);
public:
	CRhombus(Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	bool IsInside(int x, int y);
<<<<<<< HEAD
	virtual void SetCenter(Point Center);   //change the figure's center
=======
	virtual void Save(ofstream &OutFile, string filename);
>>>>>>> 048db81ab61d8e51dad859f041d42eaa3ecfee5a
};
