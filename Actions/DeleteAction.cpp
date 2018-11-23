#include "DeleteAction.h"


#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DeleteAction::DeleteAction(ApplicationManager *pApp):Action(pApp){}

void DeleteAction::ReadActionParameters()
{}



void DeleteAction::Execute()
{
	Output * pOut = pManager->GetOutput();

	if(pManager->GetSelected())
	{
		pOut->PrintMessage("The figure is deleted");
		pManager->DeleteSelectedFigure();
	}
	else
		pOut->PrintMessage("Please select a figure first");
}
