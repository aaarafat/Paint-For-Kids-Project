#include "SaveAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


SaveAction::SaveAction(ApplicationManager *pApp):Action(pApp)
{
}


void SaveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	FileName = pIn->GetSrting(pOut);
	OutFile.open(FileName);
}
void SaveAction::Execute(){
	//This action needs to read some parameters first
	ReadActionParameters();
	//Calls SaveAll() from Application Manager
	pManager->SaveAll(OutFile, colors, figures);
	OutFile.close();
}