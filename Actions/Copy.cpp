#include "Copy.h"



Copy::Copy(ApplicationManager *pApp) : Action(pApp){}
void Copy::ReadActionParameters(){
	CopiedF = pManager->GetSelected();
	
		
}

void Copy::Execute()
{
	Output * pOut = pManager->GetOutput();
	ReadActionParameters();


	if(CopiedF!=NULL){ pManager->setClipboard(CopiedF);
	pOut->PrintMessage("The figure is Copied");
	}
}
