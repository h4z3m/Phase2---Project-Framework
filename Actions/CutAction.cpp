#include "CutAction.h"

CutAction::CutAction(ApplicationManager* pApp) :Action(pApp)
{
}

void CutAction::ReadActionParameters()
{
	//Get a Pointer to the Output Interfaces
	Output* pOut = pManager->GetOutput();

}

void CutAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("You have Cut the selected figure");

	//This action needs to read some parameters first
	vector <CFigure*> selItems = pManager->GetFigVector();
	bool IsFigSelected = false;
	pManager->RemoveFig(selItems);
	pManager->set_Clipboard(selItems);
	
	
}
