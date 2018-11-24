#include "Paste.h"


Paste::Paste(ApplicationManager *pApp):Action(pApp)
{
}

void Paste::ReadActionParameters()
{
	CopiedF = pManager->getClipboard();
	if(CopiedF)
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

void Paste::Execute()
{
	Output * pOut = pManager->GetOutput();
	Input * pIn = pManager->GetInput();
	ReadActionParameters();

	if (CopiedF)
	{
		Point Center;
		pOut->PrintMessage("Paste : Click on the new figure's place");
		pIn->GetPointClicked(Center.x,Center.y);
		CheckPoint(Center, pOut, pIn);
		pOut->ClearStatusBar();
		CopiedF->SetCenter(Center);
		CopiedF->SetSelected(false);
		if(pManager->GetSelected())
		{
			pManager->GetSelected()->SetSelected(false);
			pManager->AddSelected(NULL);
		}
		pManager->AddFigure(CopiedF);
	}

}