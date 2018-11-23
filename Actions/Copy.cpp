#include "Copy.h"



Copy::Copy(ApplicationManager *pApp) : Action(pApp){}
void Copy::ReadActionParameters(){
	CopiedF = pManager->GetSelected();
	
		
}

void Copy::Execute()
{
	Output * pOut = pManager->GetOutput();
	ReadActionParameters();


	if(CopiedF!=NULL){
		if(dynamic_cast<CLine*>(CopiedF))
		{
			CopiedF = new CLine(*dynamic_cast<CLine*>(CopiedF));
		}
		else if(dynamic_cast<CRhombus*>(CopiedF))
		{
			CopiedF = new CRhombus(*dynamic_cast<CRhombus*>(CopiedF));
		}
		else if(dynamic_cast<CTriangle*>(CopiedF))
		{
			CopiedF = new CTriangle(*dynamic_cast<CTriangle*>(CopiedF));
		}
		else if (dynamic_cast<CRectangle*>(CopiedF))
		{
			CopiedF = new CRectangle(*dynamic_cast<CRectangle*>(CopiedF));
		}
		else
		{
			CopiedF = new CElipse(*dynamic_cast<CElipse*>(CopiedF));
		}	
	pManager->setClipboard(CopiedF);
	pOut->PrintMessage("The figure is Copied");
	}
}
