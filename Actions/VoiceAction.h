#pragma once
#include "action.h"

class VoiceAction :
	public Action
{
public:
	VoiceAction(ApplicationManager* pApp);
	
	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	
	//excutes action

	virtual void Execute();
};

