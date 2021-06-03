#include "SwtichToDrawMode.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"



SwitchToDrawAction::SwitchToDrawAction(ApplicationManager* pApp) : Action(pApp) {}

void SwitchToDrawAction::ReadActionParameters() {



}

//Execute the action
void SwitchToDrawAction::Execute() {

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->ClearStatusBar();
	pOut->CreateDrawToolBar();



}