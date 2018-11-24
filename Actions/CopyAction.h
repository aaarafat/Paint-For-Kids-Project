#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CRhombus.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CElipse.h"
#include "..\Figures\CRectangle.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
class CopyAction :public Action
{

	CFigure *CopiedF;
public:
    CopyAction(ApplicationManager *pApp);

	//ReadsEllipse parameters
	virtual void ReadActionParameters();
	
	//Add Ellipse to the ApplicationManager

	virtual void Execute();
};

