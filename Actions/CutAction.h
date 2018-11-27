#pragma once
#include "action.h"
class CutAction :
	public Action
{
private:
	Point P1;
	class CFigure *CopiedF; // pointer to the selected fig
public:
	CutAction(ApplicationManager*);

	
	virtual void ReadActionParameters();
	
	
	virtual void Execute();
};

