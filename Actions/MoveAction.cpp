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

	int VectorSize = pManager->GetVectorSize();

	if (VectorSize == 0) {
		SelectedFlag = false;
	}
	else {



		SelectedFlag = true;
		pOut->PrintMessage("Choose a Point to move to it");

		pIn->GetPointClicked(newPoint.x, newPoint.y); // get the new Point

		//check validation of point
		if (newPoint.y < UI.StatusBarHeight || newPoint.y > UI.height - UI.ToolBarHeight) {
			pOut->PrintMessage("Not a valid point ya haywan");

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

	if (SelectedFlag == true) {
		MainRefrence = pManager->MakeRefrencePoint(); //GET A REFRENCE POINT TO MOVE THE FIGURES WITH RESPECT TO IT  

		int VectorSize = pManager->GetVectorSize();

		CFigure* FigPtr;


		// LOOP TO CHECK EACH FIGURE OF THE SELECTED FIGURES WITH ITS OWN
		for (int i = 0; i < VectorSize; i++) {


			FigPtr = pManager->MoveLoop();

			FigPtr->ChangeCorners(newPoint, MainRefrence);
			pOut->ClearStatusBar();

		}

		pManager->ResetCount();
	}

	else
		pOut->PrintMessage("Select a figure first ya behema");

}

