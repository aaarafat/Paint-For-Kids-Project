#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CRhombus.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CElipse.h"
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

