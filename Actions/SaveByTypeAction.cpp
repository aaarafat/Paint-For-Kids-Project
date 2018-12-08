#include "SaveByTypeAction.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CElipse.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CRhombus.h"
#include "..\Figures\CLine.h"
#include "..\GUI\UI_Info.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\DEFS.h"

SaveByTypeAction::SaveByTypeAction(ApplicationManager *pApp):Action(pApp)
{
}


void SaveByTypeAction::ReadActionParameters(){
	
	pOut = pManager->GetOutput();
	pOut->PrintMessage("choose the type of the figure you want to save");
	pIn = pManager->GetInput();
	ActionType a;
	do{
	a=pIn->GetUserAction();
	switch(a){
		case DRAW_RECT:
			type=1;
			break;
		case DRAW_LINE:
			type=2;
			break;
		case DRAW_TRI:
			type=3;
			break;
		case DRAW_ELLIPSE:
			type=5;
			break;
		case DRAW_RHOMBUS:
			type=4;
			break;
		default:
			break;
	}
	}
	while(type!=1&&type!=2&&type!=3&&type!=4&&type!=5);
		FileName = pIn->GetSrting(pOut);
	OutFile.open(FileName);
}


void SaveByTypeAction::Execute(){
	ReadActionParameters();
	
	pManager->SaveAFig(type,OutFile,colors, figures);
	OutFile.close();
}
