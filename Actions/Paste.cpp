#include "Paste.h"


Paste::Paste(ApplicationManager *pApp):Action(pApp)
{
}

void Paste::ReadActionParameters()
{
	CopiedF = pManager->getClipboard();
	if(CopiedF)
	{
		
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