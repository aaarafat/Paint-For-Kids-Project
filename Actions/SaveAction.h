#pragma once
#include "action.h"
class SaveAction :
	public Action
{
	string FileName;
	ofstream OutFile;
	ofstream figures;
	ofstream colors;
public:
	SaveAction(ApplicationManager *pApp);

	//Reads action parameters
	virtual void ReadActionParameters();
	
	//excutes action

	virtual void Execute();
};

