#pragma once
#include "action.h"
class ByTypeAction :
	public Action
{
public:
	ByTypeAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();


	virtual void Execute();
};

