#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	//Rectangle corners
	Point Corner1;	
	Point Corner2;
public:
	CRectangle();
	bool IsInside(int x, int y);  //Checks that the point is inside the rectangle
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;  //Draw the rectangle
	virtual void SetCenter(int& x, int& y);   //change the figure's center
	virtual void Save(ofstream &OutFile, ofstream& colors, ofstream& figures);  //save the rectangle
	void Load(ifstream &Infile); //load the rectangle
	virtual void PrintInfo(Output* pOut);  //print the rectangle info
	virtual void setType();  //sets the figure type
	virtual int getType();	 //gets the figure type
	virtual void Resize(float frac, bool& flag);   //Resizes the rectangle 
};

#endif