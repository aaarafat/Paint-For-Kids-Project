#pragma once
#include <windows.h>
#include "action.h"
class ToPlayMode :
	public Action
{
	ofstream OutFile;
public:
	ToPlayMode(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};

