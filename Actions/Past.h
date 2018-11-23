#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

class Past :
	public Action
{
	CFigure* CopiedF;
public:
	Past(ApplicationManager *pApp);
	
	virtual void ReadActionParameters();

	virtual void Execute();

};

