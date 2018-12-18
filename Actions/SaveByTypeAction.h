#pragma once
#include "Action.h"
class SaveByTypeAction :
	public Action
{
	string FileName;   //the file name
	ofstream OutFile;  //switch file
	ofstream colors;   //colors file
	ofstream figures;  //figures file
	//Pointers to the Input and Output classes
	Output *pOut;
	Input *pIn;  
	int type;  //Type number
public:
	SaveByTypeAction(ApplicationManager *pApp);

	//Reads action parameters
	virtual void ReadActionParameters();
	
	//excutes action
	virtual void Execute();
};

