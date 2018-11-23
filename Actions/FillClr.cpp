#include "FillClr.h"


FillClr::FillClr(ApplicationManager *pApp): Action(pApp)
{
}

void FillClr::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->CreateColorBar(MODE_CLR_F);
	
	switch (pManager->GetUserAction())
	{
	case CLR_BLACK_F:
			UI.FillColor = BLACK;
			pOut->Create2ndToolBar();
			pOut->ClearStatusBar();
			break;
		case CLR_WHITE_F:
			UI.FillColor = WHITE;
			pOut->Create2ndToolBar();
			pOut->ClearStatusBar();
			break;
		case CLR_GREEN_F:
			UI.FillColor = GREEN;
			pOut->Create2ndToolBar();
			pOut->ClearStatusBar();
			break;
		case CLR_RED_F:
			UI.FillColor = RED;
			pOut->Create2ndToolBar();
			pOut->ClearStatusBar();
			break;
		case CLR_BLUE_F:
			UI.FillColor = BLUE;
			pOut->Create2ndToolBar();
			pOut->ClearStatusBar();
			break;
	}

}

void FillClr::Execute()
{
	ReadActionParameters();
	CFigure* F = pManager->GetSelected();
	if (F != NULL)
	{
		F->ChngFillClr(UI.FillColor);
		F->SetSelected(false);
	}
	else
	{
		ActGfxInfo.isFilled = true;
	}
}
