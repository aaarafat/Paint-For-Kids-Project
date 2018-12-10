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
	SetFileAttributes("SWITCH", FILE_ATTRIBUTE_NORMAL);
	InFile.open("SWITCH");
}

void ToDrawMode::Execute()
{
	ReadActionParameters();

	pManager->LoadAll(InFile);
	InFile.close();
	remove( "SWITCH" );
	remove( "C.KKK" );
	remove( "F.KKK" );

}

