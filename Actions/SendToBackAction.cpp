#include "SendToBackAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SendToBackAction::SendToBackAction(ApplicationManager* pApp) :  Action(pApp)
{
}

void SendToBackAction::ReadActionParameters()
{
	//Create new array similar to figlist
	for (int i=0; i < 200; i++) {
		newFigList [i]= NULL;
	}

	int sel = (pManager->SelectedNumber()) - 1;
	
}

void SendToBackAction::Execute()
{
	ReadActionParameters();
	vector<CFigure*> selectedFigs = pManager->GetFigVector();

	//Put selected figures in new figlist
	if (selectedFigs.size() != 0) {
		for (int i = 0; i < pManager->SelectedNumber() - 1; i++) {
			newFigList[i] = selectedFigs[i];
		}

		pManager->ReorderFigList(newFigList, 0, pManager->SelectedNumber());
	}
}
