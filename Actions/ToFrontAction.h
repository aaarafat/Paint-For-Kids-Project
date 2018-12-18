#pragma once
#include "action.h"
class ToFrontAction :
	public Action
{
	CFigure* F;   //Pointer to a figure
public:
    ToFrontAction(ApplicationManager *pApp);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	
	//Execute action
	virtual void Execute();
};

