#include "BringToFrontAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

BringToFrontAction::BringToFrontAction(ApplicationManager* pApp) : Action(pApp)
{
}

void BringToFrontAction::ReadActionParameters()
{

	int sel = (pManager->SelectedNumber()) - 1;
	
}

void BringToFrontAction::Execute()
{
	ReadActionParameters();
	vector<CFigure*> selectedFigs = pManager->GetFigVector();
//Put selected figures in new figlist
	if (selectedFigs.size() != 0) {
		pManager->ReorderFigList(selectedFigs, 1, pManager->SelectedNumber());
	}
}
