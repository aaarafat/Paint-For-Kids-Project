#pragma once
#include "Action.h"
class AddRhombAction :	public Action
{
private:
	Point P; //Rhombus Center
	GfxInfo RhomGfxInfo;
public:
	AddRhombAction(ApplicationManager *pApp);

	//Reads rhombus parameters
	virtual void ReadActionParameters();
	
	//Add rhombus to the ApplicationManager

	virtual void Execute();
	
};

