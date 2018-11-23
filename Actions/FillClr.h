#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\Figures\CLine.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


class FillClr :
	public Action
{
	bool flag; // flag to check if the user didn`t click on the color icons
public:
	FillClr(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

