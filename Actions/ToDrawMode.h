#pragma once
#include "action.h"
class ToDrawMode :
	public Action
{
	ifstream InFile;  //Pointer to the switch file
public:
	ToDrawMode(ApplicationManager *pApp);
	
	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	
	
	//Execute action
	virtual void Execute();

};

