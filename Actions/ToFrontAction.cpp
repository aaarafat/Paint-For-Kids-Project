#include "ToFrontAction.h"


ToFrontAction::ToFrontAction(ApplicationManager* pApp) : Action(pApp)
{
}

void ToFrontAction::ReadActionParameters()
{
	F = pManager->GetSelected();
}
void ToFrontAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	if(F)
	{
		pManager->ReOrderList(true);
	}
	else
	{
		pOut->PrintMessage("You should select a figure first");	
	}



}
