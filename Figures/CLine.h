#ifndef CLINE_H
#define CLINE_H

#include "CFigure.h"

class CLine :
	public CFigure
{
private:
	Point Point1;   //first corner of the line
	Point Point2;	//second corner of the line
	float area(int x1, int y1, int x2, int y2, int x3, int y3);  //area
public:
	CLine();
	CLine(Point, Point, GfxInfo FigureGfxInfo); //constructor for line 
	virtual void Draw(Output* pOut) const; //draw function for line
	virtual bool IsInside(int x, int y);  //Checks that the point is inside the line
	virtual void SetCenter(int& x, int& y);  //Sets the center
	virtual void Save(ofstream &OutFile, ofstream& colors, ofstream& figures);   //Save the line
 	void Load(ifstream &Infile);  //Load the line
	virtual void PrintInfo(Output* pOut);   //print the line's info
	virtual void setType();   //Sets the figure type
	virtual int getType();    //Gets the figure type
	virtual void Resize(float frac, bool& flag);   //Resizes the line 
};

#endif
