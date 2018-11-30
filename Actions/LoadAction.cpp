#include "LoadAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

LoadAction::LoadAction(ApplicationManager* pApp) : Action(pApp)
{
}


void LoadAction::ReadActionParameters(){
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	FileName = pIn->GetSrting(pOut);
	InFile.open(FileName);
}
void LoadAction::Execute(){
	Output* pOut = pManager->GetOutput();
	//This action needs to read some parameters first
	ReadActionParameters();
	//Calls LoadAll() from Application Manager
	if (InFile.is_open())
	{
	pManager->LoadAll(InFile);
	InFile.close();
	}
	else pOut->PrintMessage("File Not Found!");
}