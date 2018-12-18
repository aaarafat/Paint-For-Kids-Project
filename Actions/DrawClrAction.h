#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

class DrawClrAction :
	public Action
{
public:
	DrawClrAction(ApplicationManager *pApp);
	
	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	
	//Execute action
	virtual void Execute();
};

