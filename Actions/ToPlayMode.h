#pragma once

#include "action.h"
class ToPlayMode :
	public Action
{
	ofstream OutFile;	//pointer to the switch file
	ofstream figures;   //pointer to the figures file
	ofstream colors;   //pointer to the colors file
public:
	ToPlayMode(ApplicationManager *pApp);
	
	//Reads parameters required for action to execute
	virtual void ReadActionParameters();

	//Execute action
	virtual void Execute();

};

