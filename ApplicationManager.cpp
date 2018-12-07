#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddEliAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\ToDrawMode.h"
#include "Actions\ToPlayMode.h"
#include "Actions\SelectAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\AddRhombAction.h"
#include "Actions\DeleteAction.h"
#include "Actions\FillClrAction.h"
#include "Actions\DrawClrAction.h"
#include "Actions\CopyAction.h"
#include "Actions\PasteAction.h"
#include "Actions\CutAction.h"
#include "Actions\SaveAction.h"
#include "Actions\LoadAction.h"
#include "Actions\ByTypeAction.h"
#include "GUI\UI_Info.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include <iostream>

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	SelectedFig = NULL;
	Clipboard = NULL;
	FigCount = 0;
	isCut = false;
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
			pAct = new FillClrAction(this);
			break;
		case CHNG_DRAW_CLR:
			pAct = new DrawClrAction(this);
			break;
		case SELECT:
			pAct = new SelectAction(this);
			break;
		case TO_PLAY:
			pAct = new ToPlayMode(this);
			break;
		case TO_DRAW:
			pAct = new ToDrawMode(this);
			break;
		case COPY:
			pAct = new CopyAction(this);
			break;
		case CUT:
			pAct = new CutAction(this);
			break;
		case PASTE:
			pAct = new PasteAction(this);
			break;
		case SAVE:
			pAct = new SaveAction(this);
			break;
        case LOAD:
			pAct = new LoadAction(this);
			break;
		case CHOOSE_BYTYPE:
			pAct = new ByTypeAction(this);
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
	if(SelectedFig!=NULL) SelectedFig->PrintInfo(pOut);
}


void ApplicationManager::setClipboard(CFigure *C){
	if(Clipboard && !isCut)
	{
		delete Clipboard;
	}
	Clipboard = C;
}
void ApplicationManager::Cut(bool c)
{
	isCut = c;
}
bool ApplicationManager::IsCut() const
{
	return isCut;
}
CFigure* ApplicationManager::CutFig() const
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->isCut())
		{
			return FigList[i];
		}
	}
	return NULL;
}
CFigure *ApplicationManager::getClipboard() const { return Clipboard; }

//need to be put in DeleteAction class
void ApplicationManager::DeleteFigure(CFigure* F)
{
	int selectedfigureindex;
	for (int i = 0; i<FigCount; i++)
	{
		if(F==FigList[i])
		{
			selectedfigureindex=i;
		}
	}
	CFigure* temp;
	for(int i=selectedfigureindex;i<FigCount-1;i++)
	{
		temp = FigList[i];
		FigList[i]=FigList[i+1];
		FigList[i+1] = temp;
		
	}
	delete FigList[FigCount-1];
	FigCount--;
	pOut->ClearDrawArea();
}
void ApplicationManager::SaveAll(ofstream &OutFile, ofstream& colors, ofstream& figures)
{

	OutFile<<pOut->strDrawClr()<<"    "<<pOut->strFillClr()<<endl;
	OutFile<<FigCount<<endl;
	for(int i = 0; i < FigCount; i++)
	{
		FigList[i]->Save(OutFile, colors, figures);
	}

}
void ApplicationManager::LoadAll(ifstream &InFile)
{
	string fc,dc;
	int s;
	InFile>>dc>>fc;
	InFile>>s;
	pOut->ClearDrawArea();
	DelFigList();
	FigCount = 0;
	string t;
	for(int i = 0; i < s; i++)
	{
		CFigure* F;
		string type;
		InFile>>type;
		if(type=="RECTANGLE") F=new CRectangle;
		else if(type=="LINE")F=new CLine;
		else if(type=="TRIANGLE")F=new CTriangle;
		else if(type=="RHOMBUS")F=new CRhombus;
		else if(type=="ELLIPSE")F=new CElipse;
		F->setType();
		F->Load(InFile);
		AddFigure(F);
	}
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
	pOut->ClearDrawArea();
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

void ApplicationManager::DelFigList()
{	
	for(int i=0; i<FigCount; i++)
	{
		delete FigList[i];
	}
}
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	DelFigList();
	if(Clipboard)
	{
		delete Clipboard;
	}
	delete pIn;
	delete pOut;
	
}



