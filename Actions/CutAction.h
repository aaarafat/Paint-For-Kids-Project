#pragma once
#include "action.h"
class CutAction :
	public Action
{
private:
	class CFigure *CopiedF; // pointer to the selected fig
public:
	CutAction(ApplicationManager*);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	
	//Execute action
	virtual void Execute();
};

