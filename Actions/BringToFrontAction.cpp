#include "BringToFrontAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

BringToFrontAction::BringToFrontAction(ApplicationManager* pApp) : Action(pApp)
{
}

void BringToFrontAction::ReadActionParameters()
{	
}

void BringToFrontAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	if (pManager->SelectedNumber() > 0) {

		pManager->ReorderFigList(pManager->GetFigVector(), 1, pManager->SelectedNumber());
		pOut->ClearStatusBar();
	}
}
