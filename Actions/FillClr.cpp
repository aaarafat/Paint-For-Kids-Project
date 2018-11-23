#include "FillClr.h"


FillClr::FillClr(ApplicationManager *pApp): Action(pApp)
{
}


void FillClr::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->CreateColorBar();
	pOut->PrintMessage("Choose the filling color, Click at the empty area to cancel");
	flag = true;
	ActionType act = pManager->GetUserAction();
	switch (act)
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
			flag = false;
			pOut->Create2ndToolBar();
			pOut->ClearStatusBar();
			break;
	}

}

void FillClr::Execute()
{
	ReadActionParameters();
	CFigure* F = pManager->GetSelected();
	if(dynamic_cast<CLine*>(F))
	{
		F->SetSelected(false);
		pManager->AddSelected(NULL);
		ActGfxInfo.isFilled=true;
		return;
	}

	if(flag)
	{
		if (F)
		{
			F->ChngFillClr(UI.FillColor);
			F->SetSelected(false);
			pManager->AddSelected(NULL);
		}
		ActGfxInfo.isFilled=true;
	}
	else if(F)
	{
		F->SetSelected(false);
		pManager->AddSelected(NULL);
	}

}
