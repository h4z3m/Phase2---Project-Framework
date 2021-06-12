#include "RotateAction.h"
RotateAction::RotateAction(ApplicationManager* pApp) :Action(pApp)
{}

void  RotateAction::ReadActionParameters()
{}

void RotateAction::Execute() {
	vector <CFigure*> SelItems = pManager->GetFigVector();
	for (int i = 0; i < SelItems.size(); i++) {
		switch (SelItems[i]->FigType) {
		case line:
			Point MainRefrence = pManager->MakeRefrencePoint(); //GET A REFRENCE POINT TO MOVE THE FIGURES WITH RESPECT TO IT  
			SelItems[i]->Rotate(0);
			break;
		case circle:
			SelItems[i]->Rotate(0);

			break; 
		case rectangle:
			SelItems[i]->Rotate(0);

			break;
		case triangle:
			SelItems[i]->Rotate(0);
			break;
		default:
			break;

		}
	}
}

