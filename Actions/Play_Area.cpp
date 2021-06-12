#include "Play_Area.h"


Play_Area::Play_Area(ApplicationManager* pApp) : Action (pApp){
	CorrectSelections = 1;
	WrongSelections = 0;
	GoNext = 0;
	WorongCount = 0;
	PastWrongSlection = false;


}

void Play_Area::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	Point P1;

	//pManager->AreaLoop();

	pOut->PrintMessage("Select the smallest figure");

	pIn->GetPointClicked(P1.x, P1.y); // get the Point

	//check validation of point
	if (P1.y < UI.StatusBarHeight || P1.y > UI.height - UI.ToolBarHeight) {
		pOut->PrintMessage("Not a valid point ya haywan");

		bool NotInValidPoint = true;
		while (NotInValidPoint) {
			pIn->GetPointClicked(P1.x, P1.y); // get the new Point
			if (!(P1.y < UI.StatusBarHeight || P1.y > UI.height - UI.ToolBarHeight)) {
				NotInValidPoint = false;
				pOut->ClearStatusBar();
			}
		}

	}

	 StartFig = pManager->GetFigure(P1.x, P1.y);

	if (StartFig == NULL) {

		pOut->PrintMessage("ba2olak select a figure ya ahtal");

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

	pManager->CreateCirAreasVector();
	pManager->CreateLinAreasVector();
	pManager->CreateTriAreasVector();
	pManager->CreateRecAreasVector();

	if (!(pManager->CheckSmallest(StartFig))) {

		pOut->PrintMessage("yasta selecte the smallest yasta bellah 3alek");

		bool NotInValidPoint = true;
		while (NotInValidPoint) {

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

	ReadActionParameters();

	StartFig->SetHidden(true);
	pManager->UpdateInterface();

	Point P2;

	CRectangle* rect = dynamic_cast<CRectangle*> (StartFig);
	CLine* line = dynamic_cast<CLine*> (StartFig);
	CTriangle* tri = dynamic_cast<CTriangle*> (StartFig);
	CCircle* cir = dynamic_cast<CCircle*> (StartFig);

	if (rect != NULL) {
		pOut->PrintMessage("select the next largest rectangle");

		for (int i = 0; i < pManager->GetRectCount() - 1; i++) {

			pIn->GetPointClicked(P2.x, P2.y); // get the new Point

				//check validation of point
	if (P2.y < UI.StatusBarHeight || P2.y > UI.height - UI.ToolBarHeight) {
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

	CFigure* NextFig = pManager->GetFigure(P2.x, P2.y);

			
			if (NextFig != NULL && !(NextFig->IsHidden())) {
				if (NextFig->GetArea() == pManager->GetNextRecArea(GoNext + 1)) {

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
				else if (NextFig->GetArea() != pManager->GetNextRecArea(GoNext + 1)) {
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
				
			}

			else {
				pOut->PrintMessage("ba2olak select a figure ya ahtal");
				i--;
					}
				
			




		}

		
		pOut->ClearStatusBar();
		pOut->PrintMessage("Final Score: " + std::to_string( (CorrectSelections*1.0 / pManager->GetRectCount())*100 ) + "%" );



	}






	if (cir != NULL) {
		pOut->PrintMessage("select the next largest circle");

		for (int i = 0; i < pManager->GetCirCount() - 1; i++) {

			pIn->GetPointClicked(P2.x, P2.y); // get the new Point

							//check validation of point
			if (P2.y < UI.StatusBarHeight || P2.y > UI.height - UI.ToolBarHeight) {
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

			CFigure* NextFig = pManager->GetFigure(P2.x, P2.y);



			if (NextFig != NULL && !(NextFig->IsHidden())) {
				if (NextFig->GetArea() == pManager->GetNextCirArea(GoNext + 1)) {

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
				else {
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

			}
			else {
				pOut->PrintMessage("ba2olak select a figure ya ahtal");
				i--;
			}



		}


		pOut->ClearStatusBar();
		pOut->PrintMessage("Final Score: " + std::to_string((CorrectSelections * 1.0 / pManager->GetCirCount()) * 100) + "%");



	}



	if (line != NULL) {
		pOut->PrintMessage("select the next largest line");

		for (int i = 0; i < pManager->GetLineCount() - 1; i++) {

			pIn->GetPointClicked(P2.x, P2.y); // get the new Point

							//check validation of point
			if (P2.y < UI.StatusBarHeight || P2.y > UI.height - UI.ToolBarHeight) {
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

			CFigure* NextFig = pManager->GetFigure(P2.x, P2.y);


			if (NextFig != NULL && !(NextFig->IsHidden())) {
				if (NextFig->GetArea() == pManager->GetNextLinArea(GoNext + 1)) {

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
				else {
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


			}
			else {
				pOut->PrintMessage("ba2olak select a figure ya ahtal");
				i--;
			}


		}


		pOut->ClearStatusBar();
		pOut->PrintMessage("Final Score: " + std::to_string((CorrectSelections * 1.0 / pManager->GetLineCount()) * 100) + "%");



	}

	if (tri != NULL) {
		pOut->PrintMessage("select the next largest triangle");

		for (int i = 0; i < pManager->GetTriCount() - 1; i++) {

			pIn->GetPointClicked(P2.x, P2.y); // get the new Point

							//check validation of point
			if (P2.y < UI.StatusBarHeight || P2.y > UI.height - UI.ToolBarHeight) {
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

			CFigure* NextFig = pManager->GetFigure(P2.x, P2.y);


			if (NextFig != NULL && !(NextFig->IsHidden())) {
				if (NextFig->GetArea() == pManager->GetNextTriArea(GoNext + 1)) {

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
				else {
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

			}
			else {
				pOut->PrintMessage("ba2olak select a figure ya ahtal");
				i--;
			}


		}


		pOut->ClearStatusBar();
		pOut->PrintMessage("Final Score: " + std::to_string((CorrectSelections * 1.0 / pManager->GetTriCount()) * 100) + "%");



	}



	
}