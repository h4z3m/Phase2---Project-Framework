#include "MoveAction.h"

#include "..\Figures\CRectangle.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


MoveAction::MoveAction(ApplicationManager* pApp) : Action(pApp) {}

void MoveAction::ReadActionParameters() {


	RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();
	RectGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();
}

//Execute the action
void MoveAction::Execute() {

	ReadActionParameters();
	
	Point NewCorner1 = CenterCalc_corner1();
	Point NewCorner2 = CenterCalc_corner2();

	//Create a rectangle with the parameters read from the user
	CRectangle* R = new CRectangle(NewCorner1, NewCorner2, RectGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);


}
