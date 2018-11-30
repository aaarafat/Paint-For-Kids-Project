#pragma once
#include "Action.h"

class LoadAction :
	public Action
{  string FileName;
   ifstream InFile;
public:
	LoadAction(ApplicationManager* pApp);
	//Reads action parameters
	virtual void ReadActionParameters();
	
	//excutes action

	virtual void Execute();
};

