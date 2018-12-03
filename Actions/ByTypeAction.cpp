#include "ByTypeAction.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

ByTypeAction::ByTypeAction(ApplicationManager* pApp) : Action(pApp)
{
	UI.PickMode = MODE_BTYPE;
}

void ByTypeAction::ReadActionParameters()
{

}
void ByTypeAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ifstream InFile;
	InFile.open("SWITCH");
	string tmp;
	InFile>>tmp>>tmp;
	int n, r;
	InFile>>n;
	srand(time(NULL));
	r = rand()%(n + 1) + 2;
	//r = (r == 2) ? r = 3 : r;
	for(int i = 0; i < r - 1; i++)
	{
		InFile.ignore(1, '\n');
	}
	InFile>>tmp;
	cout<<tmp<<endl<<r<<endl;

}
