#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


class FillClr :
	public Action
{
public:
	FillClr(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

