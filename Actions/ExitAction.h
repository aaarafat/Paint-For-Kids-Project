#pragma once
#include "action.h"
class ExitAction :
	public Action
{
public:

	ExitAction(ApplicationManager *pApp);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	
	//Execute action
	virtual void Execute();
};

