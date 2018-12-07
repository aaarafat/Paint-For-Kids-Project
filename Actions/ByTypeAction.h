#pragma once
#include "action.h"
class ByTypeAction :
	public Action
{
	ifstream InFile;
	int FigC;
	string rFigure;
	Point P;
	CFigure* F;
public:
	ByTypeAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();


	virtual void Execute();
};

