#include "BringToFrontAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

BringToFrontAction::BringToFrontAction(ApplicationManager* pApp) : Action(pApp)
{
}

void BringToFrontAction::ReadActionParameters()
{
	//Create new array similar to figlist
	for (int i = 0; i < 200; i++) {
		newFigList[i] = NULL;
	}

	int sel = (pManager->SelectedNumber()) - 1;
	
}

void BringToFrontAction::Execute()
{
	ReadActionParameters();
	vector<CFigure*> selectedFigs = pManager->GetFigVector();

	//Put selected figures in new figlist
	if (selectedFigs.size() != 0) {
		for (int i = 0; i < pManager->SelectedNumber() - 1; i++) {
			newFigList[i] = selectedFigs[i];
		}

		pManager->ReorderFigList(newFigList, 1, pManager->SelectedNumber());
	}
}
