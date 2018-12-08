#include "ResizeAction.h"


ResizeAction::ResizeAction(ApplicationManager *pApp):Action(pApp)
{
}

void ResizeAction::ReadActionParameters()
{
	Fig = pManager->GetSelected();
	Output* pOut = pManager->GetOutput();
	if(Fig)
	{
		pOut->CreateReszieBar();
		pOut->PrintMessage("Resize : Choose a fraction, Click at the empty area to cancel");
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
	else
	{
		pOut->PrintMessage("please select a figure first");
		flag = false;
	}
}

void ResizeAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	if (flag)
	{
		switch (F)
		{
		case ResizeAction::QUART:
			Fig->Resize(0.25,flag);
			break;
		case ResizeAction::HLF:
			Fig->Resize(0.5,flag);
			break;
		case ResizeAction::TWO:
			Fig->Resize(2,flag);
			break;
		case ResizeAction::FOUR:
			Fig->Resize(4,flag);
			break;
		}
		pManager->AddSelected(NULL);
		Fig->SetSelected(false);
		if (!flag)
			pOut->PrintMessage("Can't do it");
	}
}