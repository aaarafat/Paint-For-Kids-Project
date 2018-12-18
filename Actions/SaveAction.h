#pragma once
#include "action.h"
class SaveAction :
	public Action
{
	string FileName;    //the file name
	ofstream OutFile;   //the switch file
	ofstream figures;   //the figures file
	ofstream colors;    //the colors file
public:
	SaveAction(ApplicationManager *pApp);

	//Reads action parameters
	virtual void ReadActionParameters();
	
	//excutes action

	virtual void Execute();
};

