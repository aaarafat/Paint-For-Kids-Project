#pragma once
#include "action.h"
class ToBackAction :
	public Action
{
	CFigure* F;   //Pointer to a figure
public:
    ToBackAction(ApplicationManager *pApp);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	
	//Execute action
	virtual void Execute();
};
