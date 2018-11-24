#include "CutAction.h"

#include "CopyAction.h"
#include "..\ApplicationManager.h"
#include"..\Figures\CFigure.h"


CutAction::CutAction(ApplicationManager* pMan):Action(pMan)
{}

void CutAction::ReadActionParameters()
{
}

void CutAction::Execute()
{

	Output* pOut = pManager->GetOutput();

	

	if(ptr1==NULL)
		pOut->PrintMessage("please selsect a figure first");
	else
	{
		ptr1=pManager->GetSelected();
		if(dynamic_cast<CLine*>(ptr1))
		{
			ptr1 = new CLine(*dynamic_cast<CLine*>(ptr1));
		}
		else if(dynamic_cast<CRhombus*>(ptr1))
		{
			ptr1 = new CRhombus(*dynamic_cast<CRhombus*>(ptr1));
		}
		else if(dynamic_cast<CTriangle*>(ptr1))
		{
			ptr1 = new CTriangle(*dynamic_cast<CTriangle*>(ptr1));
		}
		else if (dynamic_cast<CRectangle*>(ptr1))
		{
			ptr1 = new CRectangle(*dynamic_cast<CRectangle*>(ptr1));
		}
		else
		{
			ptr1 = new CElipse(*dynamic_cast<CElipse*>(ptr1));
		}	
	pManager->setClipboard(ptr1);
	pOut->PrintMessage("The figure is Cut");
	

		pManager->DeleteSelectedFigure();
		pManager->UpdateInterface();

	}
}