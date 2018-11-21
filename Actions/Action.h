#ifndef ACTION_H
#define ACTION_H

#include "..\DefS.h"
#include "..\GUI\UI_Info.h"
#include "..\GUI\Output.h"
class ApplicationManager; //forward class declaration


//Base class for all possible actions
class Action
{
protected:
	ApplicationManager *pManager;	//Actions needs AppMngr to do their job

public:
	void CheckPoint(Point&P, Output* pOut, Input* pIn)
	{
		while(P.y < UI.ToolBarHeight + 1 || P.y > UI.height - UI.StatusBarHeight - 1 || P.x < UI.ToolBarHeight + 1)
		{
			pOut->PrintMessage("Please, click on the draw area");
			pIn->GetPointClicked(P.x, P.y);
		}
	}

	Action(ApplicationManager *pApp) { pManager = pApp; }	//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters() =0;
	
	//Execute action (code depends on action type)
	virtual void Execute() =0;

};

#endif