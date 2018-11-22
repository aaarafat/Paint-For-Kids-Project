#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\ToDrawMode.h"
#include "Actions\ToPlayMode.h"
#include "Actions\AddLineAction.h"



#include "Actions\AddRhombAction.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_TRI:
			pAct = new AddTriAction(this);
		
		case DRAW_LINE:
			pAct = new AddLineAction(this);
			break;

		case DRAW_RHOMBUS:
			pAct = new AddRhombAction(this);
			break;

		case CHNG_FILL_CLR:
			pOut->CreateColorBar(MODE_CLR_F);
			break;
		case CHNG_DRAW_CLR:
			pOut->CreateColorBar(MODE_CLR_D);
			break;
		case SELECT:
			break;
		case CLR_BLACK_F:
			UI.FillColor = BLACK;
			pOut->Create2ndToolBar();
			pOut->ClearStatusBar();
			break;
		case CLR_WHITE_F:
			UI.FillColor = WHITE;
			pOut->Create2ndToolBar();
			pOut->ClearStatusBar();
			break;
		case CLR_GREEN_F:
			UI.FillColor = GREEN;
			pOut->Create2ndToolBar();
			pOut->ClearStatusBar();
			break;
		case CLR_RED_F:
			UI.FillColor = RED;
			pOut->Create2ndToolBar();
			pOut->ClearStatusBar();
			break;
		case CLR_BLUE_F:
			UI.FillColor = BLUE;
			pOut->Create2ndToolBar();
			pOut->ClearStatusBar();
			break;
		case CLR_BLACK_D:
			UI.DrawColor = BLACK;
			pOut->Create2ndToolBar();
			pOut->ClearStatusBar();
			break;
		case CLR_WHITE_D:
			UI.DrawColor = WHITE;
			pOut->Create2ndToolBar();
			pOut->ClearStatusBar();
			break;
		case CLR_GREEN_D:
			UI.DrawColor = GREEN;
			pOut->Create2ndToolBar();
			pOut->ClearStatusBar();
			break;
		case CLR_RED_D:
			UI.DrawColor = RED;
			pOut->Create2ndToolBar();
			pOut->ClearStatusBar();
			break;
		case CLR_BLUE_D:
			UI.DrawColor = BLUE;
			pOut->Create2ndToolBar();
			pOut->ClearStatusBar();
			break;
		case TO_PLAY:
			pAct = new ToPlayMode(this);
			break;
		case TO_DRAW:
			pAct = new ToDrawMode(this);
			break;
		case EXIT:
			///create Exit Action here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
