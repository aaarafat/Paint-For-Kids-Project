#include "Past.h"


Past::Past(ApplicationManager *pApp):Action(pApp)
{
}

void Past::ReadActionParameters()
{
	CopiedF = pManager->getClipboard();
}

void Past::Execute()
{
	Output * pOut = pManager->GetOutput();
	Input * pIn = pManager->GetInput();
	ReadActionParameters();

	if (CopiedF != NULL)
	{
		Point Center;
		pOut->PrintMessage("Past : Click on the new figure's place");
		pIn->GetPointClicked(Center.x,Center.y);
		pOut->ClearStatusBar();
		CopiedF->SetCenter(Center);
		CopiedF->SetSelected(false);
		pManager->AddFigure(CopiedF);
	}

}