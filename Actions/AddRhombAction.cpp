#include "AddRhombAction.h"
#include "..\Figures\CRhombus.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRhombAction::AddRhombAction(ApplicationManager * pApp):Action(pApp)
{}

void AddRhombAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rhombus: Click at the center");
	
	//Read center and store in point P
	pIn->GetPointClicked(P.x, P.y);
	CheckPoint(P, pOut, pIn);

	ActGfxInfo.isFilled = IsFilled();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	ActGfxInfo.DrawClr = pOut->getCrntDrawColor();
	ActGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddRhombAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	CRhombus *R=new CRhombus(P, ActGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}
