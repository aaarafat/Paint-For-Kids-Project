#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddEliAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\ToDrawMode.h"
#include "Actions\ToPlayMode.h"
#include "Actions\Select.h"
#include "Actions\AddLineAction.h"
#include "Actions\AddRhombAction.h"
#include "Actions\DeleteAction.h"
#include "Actions\FillClr.h"
#include "Actions\DrawClr.h"
#include "Actions\Copy.h"
#include "Actions\Paste.h"
#include "Actions\CutAction.h"
#include "GUI\UI_Info.h"
#include "GUI\Output.h"
#include "GUI\Input.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	SelectedFig = NULL;
	Clipboard = NULL;
	FigCount = 0;
	filled = false;
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
		case DRAW_ELLIPSE:
			pAct = new AddEliAction(this);
			break;

		case DRAW_TRI:
			pAct = new AddTriAction(this);
			break;

		case DRAW_LINE:
			pAct = new AddLineAction(this);
			break;

		case DRAW_RHOMBUS:
			pAct = new AddRhombAction(this);
			break;

		case CHNG_FILL_CLR:
			pAct = new FillClr(this);
			break;
		case CHNG_DRAW_CLR:
			pAct = new DrawClr(this);
			break;
		case SELECT:
			pAct = new Select(this);
			break;
		case TO_PLAY:
			pAct = new ToPlayMode(this);
			break;
		case TO_DRAW:
			pAct = new ToDrawMode(this);
			break;
		case COPY:
			pAct = new Copy(this);
			break;
		case CUT:
			pAct = new CutAction(this);
			break;
		case PASTE:
			pAct = new Paste(this);
			break;
		case EXIT:
			///create Exit Action here
			
			break;
		case DEL:
			pAct = new DeleteAction(this);
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
void ApplicationManager::AddSelected(CFigure* S)
{
	SelectedFig = S;
}


void ApplicationManager::setClipboard(CFigure *C){
	if(Clipboard)
	{
		delete Clipboard;
	}
	Clipboard = C;
}

CFigure *ApplicationManager::getClipboard() const { return Clipboard; }

//need to be put in DeleteAction class
void ApplicationManager::DeleteSelectedFigure(){
	int selectedfigureindex;
		for (int i = 0; i<FigCount; i++)
		{
			if(SelectedFig==FigList[i])
			{
				FigList[i]=NULL;
				selectedfigureindex=i;
			}
		}
		for(int i=selectedfigureindex;i<FigCount-1;i++)
		{
			FigList[i]=FigList[i+1];
		}
		SelectedFig=NULL;
		pOut->ClearDrawArea();
		FigCount--;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL

	for(int i=FigCount - 1; i>-1; i--)
	{
		if(FigList[i]->IsInside(x, y))
		{
			return FigList[i];
		}

	}
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

CFigure* ApplicationManager::GetSelected()
{
	return SelectedFig;
}
////////////////////////////////////////////////////////////////////////////////////
bool ApplicationManager::GetFilled()
{
	return filled;
}
void ApplicationManager::SetFilled()
{
	filled = true;
}

////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	if(Clipboard)
	{
		delete Clipboard;
	}
	delete pIn;
	delete pOut;
	
}



