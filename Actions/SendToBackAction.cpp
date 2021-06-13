#include "SendToBackAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SendToBackAction::SendToBackAction(ApplicationManager* pApp) :  Action(pApp)
{
}

void SendToBackAction::ReadActionParameters()
{
	

	int sel = (pManager->SelectedNumber()) - 1;
	
}

void SendToBackAction::Execute()
{
	ReadActionParameters();
	vector<CFigure*> selectedFigs = pManager->GetFigVector();

	//Put selected figures in new figlist
	if (selectedFigs.size() != 0) {

		pManager->ReorderFigList(selectedFigs, 0, pManager->SelectedNumber());
	}
}
