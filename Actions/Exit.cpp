#include "Exit.h"
#include"..\GUI\Output.h"
#include"..\GUI\Input.h"
#include "..\ApplicationManager.h"
#include "SaveAction.h"

Exit::Exit(ApplicationManager* pApp) : Action(pApp)
{
}

void Exit::ReadActionParameters()
{
}

void Exit::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Leaving so early? You forgot to save before exitting, press 'S' to save or press any other key to exit.");
	string s = pIn->GetSrting(pOut);
	if (s == "s" || s == "S") // S key is clicked
	{
		ActionType pAct = SAVE;
		pManager->ExecuteAction(pAct);
	}
	else
		pOut->PrintMessage("Goodbye (-_-;)");
}