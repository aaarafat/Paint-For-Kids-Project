#include "ToPlayMode.h"

#include"..\GUI\Output.h"
#include"..\ApplicationManager.h"

ToPlayMode::ToPlayMode(ApplicationManager *pApp):Action(pApp)
{
}

void ToPlayMode::ReadActionParameters()
{
}

void ToPlayMode::Execute()
{

	Output* pOut = pManager->GetOutput();
	SetFileAttributes("SWITCH", FILE_ATTRIBUTE_NORMAL);
	OutFile.open("SWITCH");
	colors.open("C.KKK");
	figures.open("F.KKK");
	pManager->SaveAll(OutFile, colors, figures);
	OutFile.close();
    SetFileAttributes("SWITCH", FILE_ATTRIBUTE_HIDDEN);
	pOut->CreatePlayToolBar();
	pOut->ClearStatusBar();
	pOut->PrintMessage("Choose to pick by type or by color");

}


