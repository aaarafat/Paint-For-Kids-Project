#pragma once
#include "action.h"

class VoiceAction :
	public Action
{
public:
	VoiceAction(ApplicationManager* pApp);
	
	virtual void ReadActionParameters();
	
	//excutes action

	virtual void Execute();
};

