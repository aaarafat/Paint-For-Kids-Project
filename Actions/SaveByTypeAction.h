#pragma once
#include "action.h"
class SaveByTypeAction :
	public Action
{
	string FileName;
	ofstream OutFile;
	ofstream colors;
	ofstream figures;
	Output *pOut;
	Input *pIn;
	int type;
public:
	SaveByTypeAction(ApplicationManager *pApp);

	//Reads action parameters
	virtual void ReadActionParameters();
	
	//excutes action

	virtual void Execute();
};

