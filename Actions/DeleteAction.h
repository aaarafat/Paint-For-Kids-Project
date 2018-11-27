#pragma once
#include "action.h"
class DeleteAction :
	public Action
{
	CFigure* SelectedF;    //Selected Figure
public:
	DeleteAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	void DeleteFigure(CFigure* F); //delete figure

	virtual void Execute();
};

