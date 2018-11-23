#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

class Paste :
	public Action
{
	CFigure* CopiedF;
public:
	Paste(ApplicationManager *pApp);
	
	virtual void ReadActionParameters();

	virtual void Execute();

};

