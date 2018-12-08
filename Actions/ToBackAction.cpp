#include "ToBackAction.h"


ToBackAction::ToBackAction(ApplicationManager* pApp) : Action(pApp)
{
}

void ToBackAction::ReadActionParameters()
{
	F = pManager->GetSelected();
}
void ToBackAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	if(F)
	{
		pManager->ReOrderList(false);
	}
	else
	{
		pOut->PrintMessage("You should select a figure first");	
	}



}
