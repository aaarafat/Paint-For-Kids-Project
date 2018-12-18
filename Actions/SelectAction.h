#pragma once
#include "Action.h"
class SelectAction :
	public Action
{
	Point P;   //point to detect the user's click 
public:
	SelectAction(ApplicationManager *pApp);
	
	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	
	//Execute action
	virtual void Execute();
};

