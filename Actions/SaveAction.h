#pragma once
#include "action.h"
class SaveAction :
	public Action
{
	string FileName;
	ofstream OutFile;
public:
	SaveAction(ApplicationManager *pApp);

	//Reads action parameters
	virtual void ReadActionParameters();
	
	//excutes action

	virtual void Execute();
};

