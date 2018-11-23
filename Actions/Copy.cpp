#include "Copy.h"

void Copy::ReadActionParameters(){
	CopiedF = pManager->GetSelected();
}

void Copy::Execute()
{
	ReadActionParameters();


}
