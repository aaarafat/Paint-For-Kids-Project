#include "DrawClr.h"

DrawClr::DrawClr(ApplicationManager *pApp): Action(pApp)
{
}

void DrawClr::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->CreateColorBar();
	pOut->PrintMessage("Choose the Drawing color, Click at the empty area to cancel");
	switch (pManager->GetUserAction())
	{
		case CLR_BLACK_C:
			UI.DrawColor = BLACK;
			pOut->Create2ndToolBar();
			pOut->ClearStatusBar();
			break;
		case CLR_WHITE_C:
			UI.DrawColor = WHITE;
			pOut->Create2ndToolBar();
			pOut->ClearStatusBar();
			break;
		case CLR_GREEN_C:
			UI.DrawColor = GREEN;
			pOut->Create2ndToolBar();
			pOut->ClearStatusBar();
			break;
		case CLR_RED_C:
			UI.DrawColor = RED;
			pOut->Create2ndToolBar();
			pOut->ClearStatusBar();
			break;
		case CLR_BLUE_C:
			UI.DrawColor = BLUE;
			pOut->Create2ndToolBar();
			pOut->ClearStatusBar();
			break;
		default:
			pOut->Create2ndToolBar();
			pOut->ClearStatusBar();
			break;
	}

}

void DrawClr::Execute()
{
	ReadActionParameters();
	CFigure* F = pManager->GetSelected();
	if (F)
	{
		F->ChngDrawClr(UI.DrawColor);
		F->SetSelected(false);
		pManager->AddSelected(NULL);
	}
}
