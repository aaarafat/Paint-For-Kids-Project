
#include "AddEliAction.h"
#include "f:\git project paint\project\Figures\CElipse.h"

#include "f:\git project paint\project\ApplicationManager.h"

#include "f:\git project paint\project\GUI\input.h"
#include "f:\git project paint\project\GUI\Output.h"

AddEliAction::AddEliAction(ApplicationManager * pApp):Action(pApp)
{}

void AddEliAction::ReadActionParameters()
{	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Elipse: Click at the center");
	
	//Read the Center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	CheckPoint(P1, pOut, pIn);
	EliGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	EliGfxInfo.DrawClr = pOut->getCrntDrawColor();
	EliGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddEliAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	CElipse *E=new CElipse(P1, EliGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(E);
}



