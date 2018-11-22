#pragma once
#include "action.h"
class ToDrawMode :
	public Action
{
public:
	ToDrawMode(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};

