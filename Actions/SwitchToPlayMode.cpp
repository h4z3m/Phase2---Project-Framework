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

	if (pManager->isGraphEmpty()) {
		pOut->PrintMessage("Create figures first to play");

	}
	else {
		pOut->PrintMessage("You are now on Play Mode. Please, select a game from the tool bar");
		pOut->CreatePlayToolBar();
	}



}