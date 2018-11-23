#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
class Copy :public Action
{

	CFigure *CopiedF;
public:
    Copy(ApplicationManager *pApp);

	//ReadsEllipse parameters
	virtual void ReadActionParameters();
	
	//Add Ellipse to the ApplicationManager

	virtual void Execute();
};

