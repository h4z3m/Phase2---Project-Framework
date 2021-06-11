#include "SwitchToPlayMode.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"



SwitchToPlayAction::SwitchToPlayAction(ApplicationManager* pApp) : Action(pApp) {}

void SwitchToPlayAction::ReadActionParameters() {



}

//Execute the action
void SwitchToPlayAction::Execute() {

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->ClearStatusBar();
	pOut->CreatePlayToolBar();



}