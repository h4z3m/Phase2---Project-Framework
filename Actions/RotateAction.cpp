#include "RotateAction.h"
#include <string>
using namespace std;
RotateAction::RotateAction(ApplicationManager* pApp) :Action(pApp)
{}

void  RotateAction::ReadActionParameters()
{}

void RotateAction::Execute() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (pManager->SelectedNumber()) {
		vector <CFigure*> SelItems = pManager->GetFigVector();
		string uChoice = "";
		try {
			pOut->ClearStatusBar();
			pOut->PrintMessage(" Degrees of rotation: (0) 90 degrees (1) 180 degrees (2) 270 degrees: ");
			uChoice = pIn->GetSrting(pOut).at(0);
			for (int i = 0; i < SelItems.size(); i++) {

				SelItems[i]->Rotate(stoi(uChoice));
				pOut->ClearStatusBar();
				pOut->PrintMessage(SelItems[i]->PrintInfo(pOut));

			}
		}
		catch (...) {
			pOut->PrintMessage("Please select a valid option !");
		}
	}

}

