#include "ByTypeAction.h"
#include <fstream>
#include <cstdlib>
#include <ctime>

ByTypeAction::ByTypeAction(ApplicationManager* pApp) : Action(pApp)
{
	FigC = 0;
	correct = 0;
	incorrect = 0;
	InFile.open("SWITCH");
	pManager->LoadAll(InFile);
	InFile.close();
	pManager->UpdateInterface();
}

void ByTypeAction::ReadActionParameters()
{
	InFile.open("SWITCH");
	Output* pOut = pManager->GetOutput();
	
	InFile>>rFigure>>rFigure;
	int  r;
	InFile>>tN;
	if(tN!=0)
	{
		InFile.close();
		InFile.open("F.KKK");
		srand(time(NULL));
		//Gets a random figure
		r = rand()%tN;
		for(int i = 0; i < r; i++)
		{
			InFile>>rFigure;
		}
		InFile>>rFigure;
		string t;

		InFile.close();
		InFile.open("F.KKK");
		//Counts figures of the randomized type
		for (int i = 0; i < tN; i++)
		{
			InFile>>t;
			if (t == rFigure)
			{
				FigC++;
			}
		}
	}
	InFile.close();
}

void ByTypeAction::Execute()
{
	ReadActionParameters();	

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if(tN!=0)
	{
	    pOut->PrintMessage("Pick "+rFigure);
	    while(FigC != 0)
	{
		
		    pIn->GetPointClicked(P.x,P.y);
		    if(pIn->InsidePlayArea(P.x,P.y))
			{
				F = pManager->GetFigure(P.x,P.y);
				if(F != NULL)
				{
					if(F->strType()==rFigure)
					{
						pManager->DeleteFigure(F);
						FigC--;
						correct++;
						pOut->PrintMessage("Correct Clicks: " + to_string(correct) + "  Incorrect Clicks: " + to_string(incorrect));
					}
					else 
					{
						incorrect++;
						pOut->PrintMessage("Correct Clicks: " + to_string(correct) + "  Incorrect Clicks: " + to_string(incorrect));
					}
				}
				pManager->UpdateInterface();
			}
			else if(P.y >= 0 && P.y <= UI.ToolBarHeight && P.x <= UI.MenuItemWidth * 4)
			{
				pOut->PrintMessage("Choose to pick by type or by color");
				break;
			}
	}
	if(FigC==0) pOut->PrintMessage("Well Done! Correct Clicks: " + to_string(correct) + "  Incorrect Clicks: " + to_string(incorrect));
	}
	else pOut->PrintMessage("No Figures To Pick From");

	
}
