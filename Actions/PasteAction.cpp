#include "PasteAction.h"

PasteAction::PasteAction(ApplicationManager *pApp):Action(pApp)
{
}

void PasteAction::ReadActionParameters()
{
	CopiedF = pManager->getClipboard();	
	if(CopiedF && !CopiedF->isCut())
	{
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
	}
}

void PasteAction::Execute()
{
	Output * pOut = pManager->GetOutput();
	Input * pIn = pManager->GetInput();
	ReadActionParameters();

	if (CopiedF)
	{
		if (CopiedF->isCut())
		{
			Point Center;
			pOut->PrintMessage("Paste : Click on the new figure's place");
			pIn->GetPointClicked(Center.x,Center.y);
			CheckPoint(Center, pOut, pIn);
			pOut->ClearStatusBar();
			CopiedF->SetCenter(Center.x, Center.y);
			pManager->AddSelected(NULL);
			if (pManager->getClipboard()->isCut())
			{
				pManager->setClipboard(NULL);
			}
		}
		else
		{
			Point Center;
			pOut->PrintMessage("Paste : Click on the new figure's place");
			pIn->GetPointClicked(Center.x,Center.y);
			CheckPoint(Center, pOut, pIn);
			pOut->ClearStatusBar();
			CopiedF->SetCenter(Center.x, Center.y);
			pManager->AddSelected(NULL);
			pManager->AddFigure(CopiedF);
		}
		
	}
	else
		pOut->PrintMessage("please copy/cut a figure first");
}