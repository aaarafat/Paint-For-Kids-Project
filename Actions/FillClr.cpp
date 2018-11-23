#include "FillClr.h"


FillClr::FillClr(ApplicationManager *pApp): Action(pApp)
{
}


void FillClr::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->CreateColorBar();
	pOut->PrintMessage("Choose the filling color");
	flag = true;
	switch (pManager->GetUserAction())
	{
		case CLR_BLACK_C:
			UI.FillColor = BLACK;
			pOut->Create2ndToolBar();
			pOut->ClearStatusBar();
			break;
		case CLR_WHITE_C:
			UI.FillColor = WHITE;
			pOut->Create2ndToolBar();
			pOut->ClearStatusBar();
			break;
		case CLR_GREEN_C:
			UI.FillColor = GREEN;
			pOut->Create2ndToolBar();
			pOut->ClearStatusBar();
			break;
		case CLR_RED_C:
			UI.FillColor = RED;
			pOut->Create2ndToolBar();
			pOut->ClearStatusBar();
			break;
		case CLR_BLUE_C:
			UI.FillColor = BLUE;
			pOut->Create2ndToolBar();
			pOut->ClearStatusBar();
			break;
		default:
			//flag = false;
			pOut->Create2ndToolBar();
			pOut->ClearStatusBar();
			break;
	}

}

void FillClr::Execute()
{

	ReadActionParameters();

	bool flag;
	ReadActionParameters();


	if(true)
	{
		CFigure* F = pManager->GetSelected();
		if (F != NULL)
		{
			F->ChngFillClr(UI.FillColor);
			F->SetSelected(false);
			pManager->AddSelected(NULL);
		}
		ActGfxInfo.isFilled=true;
	}
}