#include "ToDrawMode.h"
#include"..\GUI\Output.h"
#include"..\ApplicationManager.h"

ToDrawMode::ToDrawMode(ApplicationManager *pApp):Action(pApp)
{}

void ToDrawMode::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->CreateDrawToolBar();
	pOut->ClearStatusBar();
}

void ToDrawMode::Execute()
{
	ReadActionParameters();
	InFile.open("SWITCH");
	pManager->LoadAll(InFile);
	InFile.close();

}

