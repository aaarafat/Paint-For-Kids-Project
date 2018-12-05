#include "SelectAction.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SelectAction::SelectAction(ApplicationManager *pApp) : Action(pApp)
{

}
void SelectAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Select a figure or Click in an empty area to Unselect");
	pIn->GetPointClicked(P.x, P.y);
	pOut->ClearStatusBar();
}
void SelectAction::Execute()
{
	ReadActionParameters();
	CFigure* f = pManager->GetFigure(P.x, P.y);
	if(pManager->GetSelected())
	{
		pManager->GetSelected()->SetSelected(false);
	}
	if(f && f != pManager->GetSelected())
	{
		if(f->IsSelected())
		{
			f->SetSelected(false);
			pManager->AddSelected(NULL);
		}
		else
		{
			f->SetSelected(true);
			pManager->AddSelected(f);
		}
	}
	else
	{
		pManager->AddSelected(NULL);
	}

}
