#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRectAction::AddRectAction(ApplicationManager * pApp):Action(pApp)
{	
	if(UI.VoiceMode == MODE_VOICE)
	{
		mciSendString("open \"Voices\\1.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		mciSendString("play mp3 from 0 wait", NULL, 0, NULL);
		
	}
}

void AddRectAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rectangle: Click at first corner");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	CheckPoint(P1, pOut, pIn);
	pOut->PrintMessage("New Rectangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);
	CheckPoint(P2, pOut, pIn);
	ActGfxInfo.isFilled = IsFilled();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	ActGfxInfo.DrawClr = pOut->getCrntDrawColor();
	ActGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddRectAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	CRectangle *R=new CRectangle(P1, P2, ActGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
	mciSendString("close mp3", NULL, 0, NULL);
}
