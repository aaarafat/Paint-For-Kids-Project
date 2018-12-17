#include "AddEliAction.h"
#include "..\Figures\CElipse.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddEliAction::AddEliAction(ApplicationManager * pApp): Action(pApp)
{
	if(UI.VoiceMode == MODE_VOICE)
	{
		//mciSendString("open \"Voices\\5.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		//mciSendString("play mp3 from 0 wait", NULL, 0, NULL);	
		PlaySound(TEXT("Voices\\5.wav"), NULL, SND_ASYNC);
		
	}
}

void AddEliAction::ReadActionParameters()
{	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Elipse: Click at the center");
	
	
	//Read the Center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	CheckPoint(P1, pOut, pIn);
	ActGfxInfo.isFilled = IsFilled();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	ActGfxInfo.DrawClr = pOut->getCrntDrawColor();
	ActGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddEliAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create an Ellipse with the parameters read from the user
	CElipse *E=new CElipse(P1, ActGfxInfo);

	//Add the Ellipse to the list of figures
	pManager->AddFigure(E);
	//mciSendString("close mp3", NULL, 0, NULL);
}



