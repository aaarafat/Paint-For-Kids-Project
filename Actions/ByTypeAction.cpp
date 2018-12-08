#include "ByTypeAction.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

ByTypeAction::ByTypeAction(ApplicationManager* pApp) : Action(pApp)
{
	UI.PickMode = MODE_BTYPE;
	FigC = 0;
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
	srand(time(NULL));
	r = rand()%tN;
	for(int i = 0; i < r; i++)
	{
		char c;
		while (InFile.get(c)){if(c == '\n') break;}
	}
	InFile>>rFigure;
	cout<<rFigure<<endl;
	string t;

	InFile.close();
	InFile.open("F.KKK");
	for (int i = 0; i < tN; i++)
	{
		InFile>>t;
		if (t == rFigure)
		{
			FigC++;
		}
	}
	cout << FigC<<endl;
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
						pOut->PrintMessage("Pick "+rFigure);
						pManager->DeleteFigure(F);
						FigC--;
					}
					else 
						pOut->PrintMessage("Not "+rFigure);
				}
				pManager->UpdateInterface();
			}
			else
			{
				pOut->ClearStatusBar();
				break;
			}
	}
	if(FigC==0) pOut->PrintMessage("No More "+rFigure+" Play Again");
	}
	else pOut->PrintMessage("No Figures To Pick From");

	
}
