#pragma once
#include "Action.h"
class ByTypeAction :
	public Action
{
	ifstream InFile;   //Pointer to the saved figures file
	int FigC,tN;       //Fig counter
	string rFigure;    //Figure name
	Point P;		   //point to detect the user's click 
	CFigure* F;		  //pointer to the figure the user clicked
	int correct;	  //correct answers counter
	int incorrect;	  //incorrect answers counter
public:
	ByTypeAction(ApplicationManager *pApp);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();

	//Execute action
	virtual void Execute();
};

