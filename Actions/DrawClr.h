#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

class DrawClr :
	public Action
{
public:
	DrawClr(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

