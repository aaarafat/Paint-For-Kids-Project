#pragma once
#include "action.h"
class DeleteAction :
	public Action
{
	CFigure* SelectedF;    //Selected Figure
public:
	DeleteAction(ApplicationManager *pApp);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	
	void DeleteFigure(CFigure* F); //delete figure

	//Execute action
	virtual void Execute();
};

