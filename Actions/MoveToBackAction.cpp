#include "MoveToBackAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

MoveToBackAction::MoveToBackAction(ApplicationManager* pApp) :  Action(pApp)
{
}

void MoveToBackAction::ReadActionParameters()
{
	//Create new array similar to figlist
	for (int i=0; i < 200; i++) {
		newFigList [i]= NULL;
	}

	int sel = (pManager->SelectedNumber()) - 1;
	vector<CFigure*> selectedFigs = pManager->GetFigVector();
	//Put selected figures in new figlist
	for (int i = 0; i < pManager->SelectedNumber() - 1; i++) {
		newFigList[i] = selectedFigs[i];
	}
}

void MoveToBackAction::Execute()
{
	ReadActionParameters();
	pManager->ReorderFigList(newFigList,0, pManager->SelectedNumber());
}
