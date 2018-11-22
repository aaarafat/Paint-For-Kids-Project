#include "ToPlayMode.h"

#include"..\GUI\Output.h"
#include"..\ApplicationManager.h"

ToPlayMode::ToPlayMode(ApplicationManager *pApp):Action(pApp)
{}

void ToPlayMode::ReadActionParameters()
{}

void ToPlayMode::Execute()
{
	Output* pOut = pManager->GetOutput();

	pOut->ClearToolBar();

	pOut->CreatePlayToolBar();


}


