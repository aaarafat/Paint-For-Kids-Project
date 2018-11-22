#include "ToDrawMode.h"
#include"..\GUI\Output.h"
#include"..\ApplicationManager.h"

ToDrawMode::ToDrawMode(ApplicationManager *pApp):Action(pApp)
{}

void ToDrawMode::ReadActionParameters()
{}

void ToDrawMode::Execute()
{
	Output* pOut = pManager->GetOutput();

	pOut->ClearToolBar();

	pOut->CreateDrawToolBar();

}

