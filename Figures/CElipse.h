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
<<<<<<< HEAD
	virtual void SetCenter(Point Center);   //change the figure's center
=======
	virtual void Save(ofstream &OutFile, string filename);
>>>>>>> 048db81ab61d8e51dad859f041d42eaa3ecfee5a
};

