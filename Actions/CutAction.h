#pragma once
#include "action.h"
class CutAction :
	public Action
{
private:
	Point P1;
	class CFigure *ptr1;
public:
	CutAction(ApplicationManager*);

	
	virtual void ReadActionParameters();
	
	
	virtual void Execute();
};

