#pragma once
#include "action.h"
class DeleteAction :
	public Action
{
public:
	DeleteAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();


	virtual void Execute();
};

