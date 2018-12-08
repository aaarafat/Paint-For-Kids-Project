#pragma once
#include "action.h"
class ToFrontAction :
	public Action
{
	CFigure* F;
public:
    ToFrontAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	virtual void Execute();
};

