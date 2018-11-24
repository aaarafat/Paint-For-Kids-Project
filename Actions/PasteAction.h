#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CRhombus.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CElipse.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CRectangle.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

class PasteAction :
	public Action
{
	CFigure* CopiedF;
public:
	PasteAction(ApplicationManager *pApp);
	
	virtual void ReadActionParameters();

	virtual void Execute();

};

