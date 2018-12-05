#pragma once
#include <windows.h>
#include "action.h"
class ToPlayMode :
	public Action
{
	ofstream OutFile;
	ofstream figures;
	ofstream colors;
public:
	ToPlayMode(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};

