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
	int n, r;
	InFile>>n;
	srand(time(NULL));
	r = rand()%n;
	for(int i = 0; i < r; i++)
	{
		char c;
		while (InFile.get(c)){if(c == '\n') break;}
	}
	InFile>>rFigure;
	cout<<rFigure<<endl;
	string t;
	/*if (tmp == "RECTANGLE")
	{
		
		for (int i = 0; i < 6; i++)
		{
			InFile>>t;
		}
		InFile>>t;
	}
	else if (tmp == "TRIANGLE")
	{
		for (int i = 0; i < 8; i++)
		{
			InFile>>t;
		}
		InFile>>t;
	}
	else if (tmp == "RHOMBUS")
	{
		for (int i = 0; i < 4; i++)
		{
			InFile>>t;
		}
		InFile>>t;
	}
	else if (tmp == "ELLIPSE")
	{
		for (int i = 0; i < 4; i++)
		{
			InFile>>t;
		}
		InFile>>t;
	}
	else
	{
		t = "NO_FILL";
	}
	cout << t << endl;
	*/
	InFile.close();
	InFile.open("F.KKK");
	for (int i = 0; i < n; i++)
	{
		InFile>>t;
		if (t == rFigure)
		{
			FigC++;
		}
	}
	cout << FigC<<endl;
	InFile.close();
}
void ByTypeAction::Execute()
{
	ReadActionParameters();	

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Pick "+rFigure);
	while(FigC != 0)
	{
		pIn->GetPointClicked(P.x,P.y);
		if(pIn->InsidePlayArea(P.x,P.y))
		{
		 F = pManager->GetFigure(P.x,P.y);
		if(F != NULL){
			pManager->DeleteFigure(F);
			FigC--;
		}
		pManager->UpdateInterface();
		}
		else
		{
			pOut->ClearStatusBar();
			break;
		}
	}


}
