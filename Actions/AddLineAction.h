#pragma once
#include "Action.h"
class AddLineAction :
	public Action
{
private:
	Point P1, P2; //Line Corners
	GfxInfo RectGfxInfo;
public:
	AddLineAction(ApplicationManager *pApp);

	//Reads line parameters
	virtual void ReadActionParameters();
	
	//Add line to the ApplicationManager

	virtual void Execute();
};

