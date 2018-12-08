#include "ResizeAction.h"


ResizeAction::ResizeAction(ApplicationManager *pApp):Action(pApp)
{
}

void ResizeAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->CreateReszieBar();
	pOut->PrintMessage("Choose a fraction, Click at the empty area to cancel");
	flag = true;
	ActionType act = pManager->GetUserAction();
	switch (act)
	{
	case RESIZE_FRAC_QAURT:
		F = QUART;
		pOut->Create2ndToolBar();
		pOut->ClearStatusBar();
		break;
	case RESIZE_FRAC_HLF:
		F = HLF;
		pOut->Create2ndToolBar();
		pOut->ClearStatusBar();
		break;
	case RESIZE_FRAC_TWO:
		F = TWO;
		pOut->Create2ndToolBar();
		pOut->ClearStatusBar();
		break;
	case RESIZE_FRAC_FOUR:
		F = FOUR;
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

void ResizeAction::Execute()
{
	ReadActionParameters();
}