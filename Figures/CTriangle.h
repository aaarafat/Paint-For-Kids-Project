#pragma once
#include "CFigure.h"
class CTriangle :
	public CFigure
{
private:
	//Triangle corners
	Point Corner1;	
	Point Corner2;
	Point Corner3;
	float area(int x1, int y1, int x2, int y2, int x3, int y3);   //Gets the triangle area
public:
	CTriangle();
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;   //draw the triangle
	virtual bool IsInside(int x, int y);   //Checks that the point is inside the triangle
	virtual void SetCenter(int& x, int& y);   //change the figure's center
	virtual void Save(ofstream &OutFile, ofstream& colors, ofstream& figures);   //save the triangle
	void Load(ifstream &Infile);   //load the triangle
	virtual void PrintInfo(Output* pOut);   //print the triangle info
	virtual void setType();   //sets the figure type
	virtual int getType();	  //gets the figure type
	virtual void Resize(float frac, bool& flag);    //Resizes the triangle
};

