#include "SendToBackAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SendToBackAction::SendToBackAction(ApplicationManager* pApp) :  Action(pApp)
{
}

void SendToBackAction::ReadActionParameters()
{	
}

void SendToBackAction::Execute()
{
	if (pManager->SelectedNumber() > 0) {

		pManager->ReorderFigList(pManager->GetFigVector(), 0, pManager->SelectedNumber());
	}
}
