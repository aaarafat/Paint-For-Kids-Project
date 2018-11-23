#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	bool IsInside(int x, int y);
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
<<<<<<< HEAD
	virtual void SetCenter(Point Center);   //change the figure's center
=======
	virtual void Save(ofstream &OutFile, string filename);
>>>>>>> 048db81ab61d8e51dad859f041d42eaa3ecfee5a
};

#endif