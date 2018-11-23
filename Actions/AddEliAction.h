#pragma once
#include "Action.h"
class AddEliAction : public Action
{
	private:
	Point P1; //Ellipse Center
	GfxInfo EliGfxInfo;
public:
	AddEliAction(ApplicationManager *pApp);

	//ReadsEllipse parameters
	virtual void ReadActionParameters();
	
	//Add Ellipse to the ApplicationManager

	virtual void Execute();
};

