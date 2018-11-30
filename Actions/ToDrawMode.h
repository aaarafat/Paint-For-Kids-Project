#pragma once
#include "action.h"
class ToDrawMode :
	public Action
{
	ifstream InFile;
public:
	ToDrawMode(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};

