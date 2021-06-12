#include "SwitchToDrawAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
SwitchToDrawAction::SwitchToDrawAction(ApplicationManager* pApp) : Action(pApp) {}

void SwitchToDrawAction::ReadActionParameters() {
}

//Execute the action
void SwitchToDrawAction::Execute() {

	Output* pOut = pManager->GetOutput();

	//Unhide all figures before going back to Draw mode
	pManager->UnhideAllFigs();



	pOut->ClearStatusBar();
	pOut->CreateDrawToolBar();



}

