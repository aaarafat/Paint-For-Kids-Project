#include "AddLineAction.h"
#include "..\Figures\CLine.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddLineAction::AddLineAction(ApplicationManager * pApp):Action(pApp)
{
	if(UI.VoiceMode == MODE_VOICE)
	{
		PlaySound(TEXT("Voices\\2.wav"), NULL, SND_ASYNC);
	}
}

void AddLineAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Line: Click at the starting point");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	CheckPoint(P1, pOut, pIn);
	pOut->PrintMessage("New Line: Click at the end point");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);
	CheckPoint(P2, pOut, pIn);
	//get drawing, filling colors and pen width from the interface
	ActGfxInfo.DrawClr = pOut->getCrntDrawColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddLineAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a line with the parameters read from the user
	CLine *L=new CLine(P1, P2, ActGfxInfo);

	//Add the line to the list of figures
	pManager->AddFigure(L);
	//mciSendString("close mp3", NULL, 0, NULL);
}

