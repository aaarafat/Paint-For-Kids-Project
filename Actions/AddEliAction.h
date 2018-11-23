
#pragma once
#include "f:\git project paint\project\actions\action.h"
class AddEliAction : public Action
{
	private:
	Point P1; //Elipse Center
	GfxInfo EliGfxInfo;
public:
	AddEliAction(ApplicationManager *pApp);

	//Reads Eli parameters
	virtual void ReadActionParameters();
	
	//Add Eli to the ApplicationManager

	virtual void Execute();
};

