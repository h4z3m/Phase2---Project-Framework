#include "RotateAction.h"

RotateAction::RotateAction(ApplicationManager* pApp) : Action(pApp) {}

//Reads  parameters
void RotateAction::ReadActionParameters() {
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	int VectorSize = pManager->GetVectorSize();
 }

//Add  to the ApplicationManager
void RotateAction::Execute() {

	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ReadActionParameters();

	int VectorSize = pManager->GetVectorSize();

	CFigure* FigPtr;

	// LOOP TO CHECK EACH FIGURE OF THE SELECTED FIGURES WITH ITS OWN
	for (int i = 0; i < VectorSize; i++) {


		FigPtr = pManager->GetFigPtr();

		FigPtr->RotateFigure();

		pOut->ClearStatusBar();

	}

	pManager->ResetCount();
}




 

