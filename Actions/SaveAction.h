#pragma once
#include "action.h"
class SaveAction :
	public Action
{
	string FileName;
	ofstream OutFile;
public:
	SaveAction(ApplicationManager *pApp);

	//ReadsEllipse parameters
	virtual void ReadActionParameters();
	
	//Add Ellipse to the ApplicationManager

	virtual void Execute();
};

