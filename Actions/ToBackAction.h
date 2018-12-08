#pragma once
#include "action.h"
class ToBackAction :
	public Action
{
	CFigure* F;
public:
    ToBackAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	virtual void Execute();
};
