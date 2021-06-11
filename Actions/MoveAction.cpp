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

//Execute the action
void MoveAction::Execute() {

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ReadActionParameters();

	MovedFigVector = pManager->GetFigVector(); //UPDATE THE LIST OF SELECTED FIGURES 

	MainRefrence = pManager->MakeRefrencePoint(); //GET A REFRENCE POINT TO MOVE THE FIGURES WITH RESPECT TO IT  

	CRectangle* recPtr[10];
	CCircle* cirPtr[10];
	CLine* linPtr[10];
	CTriangle* triPtr[10];

	// LOOP TO CHECK EACH FIGURE OF THE SELECTED FIGURES WITH ITS OWN
	for (int i = 0; i < MovedFigVector.size(); i++) {

		//CHECK THE TYPE OF THE FIGURE 
		CRectangle* rect = dynamic_cast<CRectangle*> (MovedFigVector[i]);
		CLine* line = dynamic_cast<CLine*> (MovedFigVector[i]);
		CTriangle* tri = dynamic_cast<CTriangle*> (MovedFigVector[i]);
		CCircle* cir = dynamic_cast<CCircle*> (MovedFigVector[i]);

		//IF THE FIGURE IS RECTANGLE
		if (rect != NULL) {
			rect->ChangeRecCorners(newPoint, MainRefrence);
			pOut->ClearStatusBar();
		}

		//IF THE FIGURE IS TRIANGLE
		if (tri != NULL) {
			tri->ChangeTriPoints(newPoint, MainRefrence);
			pOut->ClearStatusBar();
		}

		//IF THE FIGURE IS LINE
		if (line != NULL) {
			line->ChangeLinPoints(newPoint, MainRefrence);
			pOut->ClearStatusBar();
		}
		else if (cir != NULL) {

			cir->ChangeCirPoints(newPoint);
			pOut->ClearStatusBar();
		}
	}
}

