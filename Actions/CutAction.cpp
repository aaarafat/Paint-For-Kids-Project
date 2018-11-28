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
		CopiedF->SetSelected(false);
		if (CopiedF->isCut())
		{
			pOut->PrintMessage("The figure is Cut");
			return;
		}
		CopiedF->Cut(true);
		if(dynamic_cast<CLine*>(CopiedF))
		{
			CopiedF = new CLine(*dynamic_cast<CLine*>(CopiedF));
		}
		else if(dynamic_cast<CRhombus*>(CopiedF))
		{
			CopiedF = new CRhombus(*dynamic_cast<CRhombus*>(CopiedF));
		}
		else if(dynamic_cast<CTriangle*>(CopiedF))
		{
			CopiedF = new CTriangle(*dynamic_cast<CTriangle*>(CopiedF));
		}
		else if (dynamic_cast<CRectangle*>(CopiedF))
		{
			CopiedF = new CRectangle(*dynamic_cast<CRectangle*>(CopiedF));
		}
		else
		{
			CopiedF = new CElipse(*dynamic_cast<CElipse*>(CopiedF));
		}
		pManager->setClipboard(CopiedF);
		
		if (pManager->IsCut()) 
			pManager->CutFig()->Cut(false);
		pManager->AddSelected(NULL);
		pManager->Cut(true);
		pOut->PrintMessage("The figure is Cut");
	}
	else
		pOut->PrintMessage("please select a figure first");	
}