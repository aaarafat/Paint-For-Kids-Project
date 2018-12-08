#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

class ResizeAction:
	public Action
{
	enum FRAC
	{
		QUART,
		HLF,
		TWO,
		FOUR,
	};
	FRAC F;
	CFigure* Fig;
	bool flag; // flag to check if the user didn`t click on the resize icons
public:
	ResizeAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

