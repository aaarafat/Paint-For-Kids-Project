#include "VoiceAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\GUI\UI_Info.h" 

VoiceAction::VoiceAction(ApplicationManager* pApp) : Action(pApp){}

void VoiceAction::ReadActionParameters(){
	if(UI.VoiceMode == MODE_MUTE) UI.VoiceMode = MODE_VOICE; 
	else UI.VoiceMode = MODE_MUTE;
}

void VoiceAction::Execute(){
	ReadActionParameters();
	Output *pOut = pManager->GetOutput();
	if(UI.VoiceMode == MODE_MUTE) pOut->PrintMessage("Voice : Mute");
	else pOut->PrintMessage("Voice : ON");
	pOut->CreateVoiceIcon();


}
