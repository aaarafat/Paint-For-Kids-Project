#pragma once
#include "action.h"
class ExitAction :
	public Action
{
public:

	ExitAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	

	virtual void Execute();
};

