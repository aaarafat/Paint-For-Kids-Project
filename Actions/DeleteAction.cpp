#include "DeleteAction.h"


#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DeleteAction::DeleteAction(ApplicationManager *pApp):Action(pApp){}

void DeleteAction::ReadActionParameters()
{
	SelectedF = pManager->GetSelected();
}
void DeleteAction::DeleteFigure(CFigure* F)
{
	pManager->DeleteFigure(F);
}

void DeleteAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();

	if(SelectedF != NULL)
	{
		DeleteFigure(SelectedF);
		pOut->PrintMessage("The figure is deleted");
		pManager->AddSelected(NULL);
		pOut->ClearStatusBar();
	}
	else
		pOut->PrintMessage("Please select a figure first");
}
