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

}

void ExitAction::Execute()
{
	ReadActionParameters();
	pManager->~ApplicationManager();
	exit(0);
}
