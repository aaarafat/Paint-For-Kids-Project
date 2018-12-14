#include "ExitAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\GUI\UI_Info.h" 

ExitAction::ExitAction(ApplicationManager *pApp):Action(pApp)
{
}


void ExitAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Press Enter To Exit");
	pIn->GetEnterPressed();
}

void ExitAction::Execute()
{
	ReadActionParameters();
}
