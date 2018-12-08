#pragma once
#include "Action.h"
class ByTypeAction :
	public Action
{
	ifstream InFile;
	int FigC,tN;
	string rFigure;
	Point P;
	CFigure* F;
	int correct;
	int incorrect;
public:
	ByTypeAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();


	virtual void Execute();
};

