#include "MoveAction.h"

#include "..\Figures\CRectangle.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

MoveAction::MoveAction(ApplicationManager* pApp) : Action(pApp) {}

void MoveAction::ReadActionParameters() {
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	int VectorSize = pManager->GetVectorSize(); //GET THE NUMBER OF SELECTED FIGURES 

	if (VectorSize == 0) { //IF THERE IS NO FIGURE SELECTED 
		SelectedFlag = false;
	}

	else { //IF THERE ARE SELECTED FIGURES, START MOVING 



		SelectedFlag = true;
		pOut->PrintMessage("Choose a Point to move to it");
		pIn->GetPointClicked(newPoint.x, newPoint.y); // get the new Point

		//check validation of point
		if (newPoint.y < UI.StatusBarHeight || newPoint.y > UI.height - UI.ToolBarHeight) {
			pOut->PrintMessage("Not a valid point");

			bool NotInValidPoint = true;
			while (NotInValidPoint) {
				pIn->GetPointClicked(newPoint.x, newPoint.y); // get the new Point
				if (!(newPoint.y < UI.StatusBarHeight || newPoint.y > UI.height - UI.ToolBarHeight)) {
					NotInValidPoint = false;
					pOut->ClearStatusBar();
				}
			}

		}
	}
	
}

//Execute the action
void MoveAction::Execute() {

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ReadActionParameters();


	if (SelectedFlag == true) { //IF THERE ARE SELECTED FIGURES, START MOVING 
		MainRefrence = pManager->MakeRefrencePoint(); //GET A REFRENCE POINT TO MOVE THE FIGURES WITH RESPECT TO IT  

		int VectorSize = pManager->GetVectorSize(); //GET THE NUMBER OF SELECTED FIGURES 

		CFigure* FigPtr;

		// LOOP TO MOVE EACH FIGURE OF THE SELECTED FIGURES WITH ITS OWN 
		for (int i = 0; i < VectorSize; i++) {

			// GET A POINTER OF THE TYPE OF THE SELECTED FIGURE 
			FigPtr = pManager->GetFigPtr();

			// CHANGE THE CORNER OF THE SPECIFIC TYPE OF THE FIGURE
			FigPtr->ChangeCorners(newPoint, MainRefrence);
			pOut->ClearStatusBar();

		}
		// RESET THE COUNTER OF THE MOVED FIGURE
		pManager->ResetCount();
	}

	//IF THERE IS NO FIGURE SELECTED 
	else 
		pOut->PrintMessage("Yasta select a figure first yasta bellah 3alek");

	}

