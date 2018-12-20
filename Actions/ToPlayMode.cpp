#include "ToPlayMode.h"

#include"..\GUI\Output.h"
#include"..\ApplicationManager.h"

ToPlayMode::ToPlayMode(ApplicationManager *pApp):Action(pApp)
{
}

void ToPlayMode::ReadActionParameters()
{
	SetFileAttributes("SWITCH", FILE_ATTRIBUTE_NORMAL);
	SetFileAttributes("C.KKK", FILE_ATTRIBUTE_NORMAL);
	SetFileAttributes("F.KKK", FILE_ATTRIBUTE_NORMAL);
	OutFile.open("SWITCH");
	colors.open("C.KKK");
	figures.open("F.KKK");
	if(pManager->getClipboard())
	{
		pManager->setClipboard(NULL);
	}
	pManager->SaveAll(OutFile, colors, figures);
	OutFile.close();
	colors.close();
	figures.close();
    SetFileAttributes("SWITCH", FILE_ATTRIBUTE_HIDDEN);
	SetFileAttributes("C.KKK", FILE_ATTRIBUTE_HIDDEN);
	SetFileAttributes("F.KKK", FILE_ATTRIBUTE_HIDDEN);
}

void ToPlayMode::Execute()
{

	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	pOut->CreatePlayToolBar();
	pOut->ClearStatusBar();
	pOut->PrintMessage("Choose to pick by type or by color");

}


