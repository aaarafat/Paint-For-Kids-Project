#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

class ResizeAction:
	public Action
{
	enum FRAC //all possible resize fractions
	{
		QUART,
		HLF,
		TWO,
		FOUR,
	};
	FRAC F;  //selected fraction
	CFigure* Fig;  //pointer to a figure to resize
	bool flag; // flag to check if the user didn`t click on the resize icons
public:
	ResizeAction(ApplicationManager *pApp);
	
	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	
	//Execute action
	virtual void Execute();
};

