#pragma once
#include "c:\users\elgeel 3\desktop\new folder (4)\new folder\project\actions\action.h"
class SaveByTypeAction :
	public Action
{
	string FileName;
	ofstream OutFile;
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

