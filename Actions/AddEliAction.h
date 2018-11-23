#pragma once
#include "Action.h"
class AddEliAction : public Action
{
	private:
	Point P1; //Ellipse Center
public:
	AddEliAction(ApplicationManager *pApp);

	//ReadsEllipse parameters
	virtual void ReadActionParameters();
	
	//Add Ellipse to the ApplicationManager

	virtual void Execute();
};

