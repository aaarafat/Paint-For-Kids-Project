#pragma once
#include "action.h"
class ToPlayMode :
	public Action
{
public:
	ToPlayMode(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};

