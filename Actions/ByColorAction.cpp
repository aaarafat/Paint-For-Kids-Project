#include "ByColorAction.h"
#include <fstream>
#include <cstdlib>
#include <ctime>

ByColorAction::ByColorAction(ApplicationManager* pApp) : Action(pApp)
{
	FigC = 0;
	correct = 0;
	incorrect = 0;
	InFile.open("SWITCH");
	pManager->LoadAll(InFile);
	InFile.close();
	pManager->UpdateInterface();
}

void ByColorAction::ReadActionParameters()
{
	InFile.open("SWITCH");
	Output* pOut = pManager->GetOutput();
	
	InFile>>rColor>>rColor;
	int r;
	InFile>>tN;
	if(tN!=0)
	{
		InFile.close();
		InFile.open("C.KKK");
		srand(time(NULL));
		//Gets a random color
		r = rand()%tN;
		for(int i = 0; i < r; i++)
		{
			InFile>>rColor;
		}
		InFile>>rColor;
		string t;

		//Counts the figures that filled with the randomized color 
		InFile.close();
		InFile.open("C.KKK");
		for (int i = 0; i < tN; i++)
		{
			InFile>>t;
			if (t == rColor)
			{
				FigC++;
			}
		}
	}
	InFile.close();
}

void ByColorAction::Execute()
{
	ReadActionParameters();	

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if(tN!=0)
	{
	    pOut->PrintMessage((rColor == "NO_FILL") ? "Pick Non Filled Figures" : "Pick "+rColor);
	    while(FigC != 0)
	{
		
		    pIn->GetPointClicked(P.x,P.y);
		    if(pIn->InsidePlayArea(P.x,P.y))
			{
				F = pManager->GetFigure(P.x,P.y);
				if(F != NULL)
				{
					if(F->strFillClr()==rColor)
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
