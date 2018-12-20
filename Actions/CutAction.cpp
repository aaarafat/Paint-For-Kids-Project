#include "CutAction.h"

#include "CopyAction.h"
#include "..\ApplicationManager.h"
#include"..\Figures\CFigure.h"


CutAction::CutAction(ApplicationManager* pMan):Action(pMan)
{}

void CutAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	CopiedF = pManager->GetSelected();
}

void CutAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	if(CopiedF){
		if (CopiedF->isCut())
		{
			pOut->PrintMessage("The figure is Cut");
			return;
		}
		CopiedF->Cut(true);
		pManager->setClipboard(CopiedF);
		pManager->AddSelected(NULL);
		pOut->PrintMessage("The figure is Cut");
	}
	else
		pOut->PrintMessage("please select a figure first");	
}