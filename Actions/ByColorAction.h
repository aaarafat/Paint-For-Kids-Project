#pragma once
#include "Action.h"
class ByColorAction :
	public Action
{
	ifstream InFile;
	int FigC,tN;
	string rColor;
	Point P;
	CFigure* F;
	int correct;
	int incorrect;
public:
	ByColorAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();


	virtual void Execute();
};

