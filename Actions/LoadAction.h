#pragma once
#include "Action.h"

class LoadAction :
	public Action
{  
	string FileName;  //the file name
	ifstream InFile;  //pointer to a file to load
public:
	LoadAction(ApplicationManager* pApp);
	
	//Reads action parameters
	virtual void ReadActionParameters();
	
	//excutes action
	virtual void Execute();
};

