#include "Play_Area.h"

// CHECK THE TYPE OF THE FIGURE 
int DoDynamicCheck(CFigure* f) {
	CRectangle* rect = dynamic_cast<CRectangle*> (f);
	CLine* line = dynamic_cast<CLine*> (f);
	CTriangle* tri = dynamic_cast<CTriangle*> (f);
	CCircle* cir = dynamic_cast<CCircle*> (f);

	//rectangle >>> 0
	//triangle >>> 1
	//circle >>> 2
	//line >>> 3
	//empty >>> 4

	if (rect != NULL)
		return 0;
	else if (tri != NULL)
		return 1;
	else if (cir != NULL)
		return 2;
	else if (line != NULL)
		return 3;
	else
		return 4;
}

void CheckValidationPoint(Point& P2, Output* pOut, Input* pIn) {

	if (P2.y < UI.StatusBarHeight || P2.y > UI.height) {
		pOut->PrintMessage("Not a valid point ya haywan");

		bool NotInValidPoint = true;
		while (NotInValidPoint) {
			pIn->GetPointClicked(P2.x, P2.y); // get the new Point
			if (!(P2.y < UI.StatusBarHeight || P2.y > UI.height - UI.ToolBarHeight)) {
				NotInValidPoint = false;
				pOut->ClearStatusBar();
			}
		}

	}
}

//IF THE SELECTION IS CORRECT 
void CorrectSelection(int& WorongCount, bool& PastWrongSlection, int& CorrectSelections,
	CFigure* NextFig, ApplicationManager* pManager, int& GoNext, Output* pOut, int& WrongSelections) {
	for (int j = 0; j < WorongCount; j++)
		if (PastWrongSlection == true)
			GoNext++;

	PastWrongSlection = false;

	CorrectSelections++;
	NextFig->SetHidden(true);
	pManager->UpdateInterface();
	GoNext++;

	WorongCount = 0;

	pOut->ClearStatusBar();
	pOut->PrintMessage("Correct Selections: " + std::to_string(CorrectSelections) + " - Wrong Selections: " + std::to_string(WrongSelections));
}

//IF THE SELECTION IS WRONG 
void WrongSelection(bool& PastWrongSlection, int& GoNext, int& WrongSelections, CFigure* NextFig, Output* pOut,
	ApplicationManager* pManager, int& CorrectSelections, int& WorongCount) {
	if (PastWrongSlection == true)
		GoNext = GoNext;

	WrongSelections++;
	NextFig->SetHidden(true);
	pManager->UpdateInterface();
	pOut->ClearStatusBar();
	pOut->PrintMessage("Correct Selections: " + std::to_string(CorrectSelections) + " - Wrong Selections: " + std::to_string(WrongSelections));
	PastWrongSlection = true;
	WorongCount++;
}

Play_Area::Play_Area(ApplicationManager* pApp) : Action(pApp) {
	CorrectSelections = 1; //START FROM 1 BECAUSE THE FIRST SELECTION IS ALWAYS CORRECT 
	WrongSelections = 0;
	GoNext = 0;
	WorongCount = 0;
	PastWrongSlection = false; //FLAG TO CHECK IF THE LAST SELECTION WAS WRONG 
}

void Play_Area::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	Point P1;

	pOut->PrintMessage("Select the smallest figure");
	pIn->GetPointClicked(P1.x, P1.y); // get the Point
	CheckValidationPoint(P1, pOut, pIn);

	StartFig = pManager->GetFigure(P1.x, P1.y);

	if (StartFig == NULL) {

		pOut->PrintMessage("Yasta select a figure yasta ARGOOK");

		bool NotInValidPoint = true;
		while (NotInValidPoint) {
			pIn->GetPointClicked(P1.x, P1.y); // get the new Point
			StartFig = pManager->GetFigure(P1.x, P1.y);

			if (!(StartFig == NULL)) {
				NotInValidPoint = false;
				pOut->ClearStatusBar();
			}
		}
	}

	pManager->CreateCirAreasVector(); //RECORD THE AREAS OF THE CIRCLES IN ONE VECTOR
	pManager->CreateLinAreasVector(); //RECORD THE AREAS OF THE LINES IN ONE VECTOR
	pManager->CreateTriAreasVector(); //RECORD THE AREAS OF THE TRIANGLES IN ONE VECTOR
	pManager->CreateRecAreasVector(); //RECORD THE AREAS OF THE RECTANGLES IN ONE VECTOR


	if (!(pManager->CheckSmallest(StartFig))) { //CHECK IF THE FIRST SELECTION WAS THE SMALLEST FIGURE OF ANY TYPE

		pOut->PrintMessage("yasta selecte the smallest yasta bellah 3alek");

		bool NotInValidPoint = true;
		while (NotInValidPoint) { //KEEP ASKING UNTIL THE USER SELECT THE SMALLEST 

			pIn->GetPointClicked(P1.x, P1.y); // get the new Point
			StartFig = pManager->GetFigure(P1.x, P1.y);

			if ((pManager->CheckSmallest(StartFig))) {
				NotInValidPoint = false;
				pOut->ClearStatusBar();
			}
		}
	}
}

void Play_Area::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	Point P2;

	pOut->PrintMessage("You should select the smallest figure to hide it, then select the next one. Click anywhere to continue");
	pIn->GetPointClicked(P2.x, P2.y); // get the new Point

	ReadActionParameters();

	StartFig->SetHidden(true);
	pManager->UpdateInterface();

	//IF THE FIRST FIGURE IS RECTANGLE
	if (DoDynamicCheck(StartFig) == 0) {

		pOut->PrintMessage("You selected the smallest rectangle. Now, select the next smallest rectangles");


		for (int i = 0; i < pManager->GetRectCountWColor(NULL) - 1; i++) {

			pIn->GetPointClicked(P2.x, P2.y); // get the new Point

			CheckValidationPoint(P2, pOut, pIn); 	//check validation of point

			CFigure* NextFig = pManager->GetFigure(P2.x, P2.y);

			if (DoDynamicCheck(NextFig) == 0) { 		//IF THE NEXT SELECTED FIGURE IS RECTANGLE

				if (!(NextFig->IsHidden())) { 		//IF THE NEXT SELECTED FIGURE IS NOT HIDDEN

					if (NextFig->GetArea() == pManager->GetNextRecArea(GoNext + 1)) { 	 //IF THE AREA OF THE NEXT SELECTED FIGURE IS NEXT RIGHT SELECTION

						CorrectSelection(WorongCount, PastWrongSlection, CorrectSelections, NextFig, pManager, GoNext, pOut, WrongSelections);
					}

					else {
						WrongSelection(PastWrongSlection, GoNext, WrongSelections, NextFig, pOut, pManager, CorrectSelections, WorongCount);
					}
				}

				else {
					pOut->PrintMessage("Wrong Selection. Try Again.");
					i--;
				}
			}

			else {
				pOut->PrintMessage("Please, select rectangles.");
				i--;
			}
		}

		pOut->PrintMessage("Final Score: " + std::to_string((CorrectSelections * 1.0 / pManager->GetRectCountWColor(NULL)) * 100) + "%");
	}


	//IF THE FIRST FIGURE IS TRIANGLE
	if (DoDynamicCheck(StartFig) == 1) {
		pOut->PrintMessage("You selected the smallest triangle. Now, select the next smallest triangles");

		for (int i = 0; i < pManager->GetTriCountWColor(NULL) - 1; i++) {

			pIn->GetPointClicked(P2.x, P2.y); // get the new Point

			CheckValidationPoint(P2, pOut, pIn); 	//check validation of point

			CFigure* NextFig = pManager->GetFigure(P2.x, P2.y);

			if (DoDynamicCheck(NextFig) == 1) { 		//IF THE NEXT SELECTED FIGURE IS TRIANGLE

				if (!(NextFig->IsHidden())) { 		//IF THE NEXT SELECTED FIGURE IS NOT HIDDEN

					if (NextFig->GetArea() == pManager->GetNextTriArea(GoNext + 1)) { 	 //IF THE AREA OF THE NEXT SELECTED FIGURE IS NEXT RIGHT SELECTION

						CorrectSelection(WorongCount, PastWrongSlection, CorrectSelections, NextFig, pManager, GoNext, pOut, WrongSelections);
					}

					else {
						WrongSelection(PastWrongSlection, GoNext, WrongSelections, NextFig, pOut, pManager, CorrectSelections, WorongCount);
					}
				}

				else {
					pOut->PrintMessage("Wrong Selection. Try Again.");
					i--;
				}
			}

			else {
				pOut->PrintMessage("Please, select triangles.");
				i--;
			}
		}

		pOut->PrintMessage("Final Score: " + std::to_string((CorrectSelections * 1.0 / pManager->GetTriCountWColor(NULL)) * 100) + "%");
	}

	//IF THE FIRST FIGURE IS CIRCLE
	if (DoDynamicCheck(StartFig) == 2) {
		pOut->PrintMessage("You selected the smallest circle. Now, select the next smallest circles");

		for (int i = 0; i < pManager->GetCirCountWColor(NULL) - 1; i++) {

			pIn->GetPointClicked(P2.x, P2.y); // get the new Point

			CheckValidationPoint(P2, pOut, pIn); 	//check validation of point

			CFigure* NextFig = pManager->GetFigure(P2.x, P2.y);

			if (DoDynamicCheck(NextFig) == 2) { 		//IF THE NEXT SELECTED FIGURE IS CIRCLE

				if (!(NextFig->IsHidden())) { 		//IF THE NEXT SELECTED FIGURE IS NOT HIDDEN

					if (NextFig->GetArea() == pManager->GetNextCirArea(GoNext + 1)) { 	 //IF THE AREA OF THE NEXT SELECTED FIGURE IS NEXT RIGHT SELECTION

						CorrectSelection(WorongCount, PastWrongSlection, CorrectSelections, NextFig, pManager, GoNext, pOut, WrongSelections);
					}

					else {
						WrongSelection(PastWrongSlection, GoNext, WrongSelections, NextFig, pOut, pManager, CorrectSelections, WorongCount);
					}
				}

				else {
					pOut->PrintMessage("Wrong Selection. Try Again.");
					i--;
				}
			}

			else {
				pOut->PrintMessage("Please, select circles.");
				i--;
			}
		}

		pOut->PrintMessage("Final Score: " + std::to_string((CorrectSelections * 1.0 / pManager->GetCirCountWColor(NULL)) * 100) + "%");
	}

	//IF THE FIRST FIGURE IS LINE
	if (DoDynamicCheck(StartFig) == 3) {
		pOut->PrintMessage("You selected the smallest line. Now, select the next smallest lines");

		for (int i = 0; i < pManager->GetLineCountWColor(NULL) - 1; i++) {

			pIn->GetPointClicked(P2.x, P2.y); // get the new Point

			CheckValidationPoint(P2, pOut, pIn); 	//check validation of point

			CFigure* NextFig = pManager->GetFigure(P2.x, P2.y);

			if (DoDynamicCheck(NextFig) == 3) { 		//IF THE NEXT SELECTED FIGURE IS LINE

				if (!(NextFig->IsHidden())) { 		//IF THE NEXT SELECTED FIGURE IS NOT HIDDEN

					if (NextFig->GetArea() == pManager->GetNextLinArea(GoNext + 1)) { 	 //IF THE AREA OF THE NEXT SELECTED FIGURE IS NEXT RIGHT SELECTION

						CorrectSelection(WorongCount, PastWrongSlection, CorrectSelections, NextFig, pManager, GoNext, pOut, WrongSelections);
					}

					else {
						WrongSelection(PastWrongSlection, GoNext, WrongSelections, NextFig, pOut, pManager, CorrectSelections, WorongCount);
					}
				}

				else {
					pOut->PrintMessage("Wrong Selection. Try Again.");
					i--;
				}
			}

			else {
				pOut->PrintMessage("Please, select lines.");
				i--;
			}
		}

		pOut->PrintMessage("Final Score: " + std::to_string((CorrectSelections * 1.0 / pManager->GetLineCountWColor(NULL)) * 100) + "%");
	}


	pManager->ResetFigAreas();
	pManager->UnhideAllFigs();

}