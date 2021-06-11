#include "AddCircleAction.h"
#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddCircleAction::AddCircleAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddCircleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at first point");

	//Read center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Circle: Click at second point");

	//Read point on circumferance and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	CircleGfxInfo.isFilled = fillClrStatus;	//default is not filled
	CircleGfxInfo.isHidden = false;
	//Get drawing, filling colors and pen width from the interface
	CircleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircleGfxInfo.FillClr = pOut->getCrntFillColor();
	CircleGfxInfo.BorderWdth = pOut->getCrntPenWidth();
	pOut->ClearStatusBar();

}

//Execute the action
void AddCircleAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a circle with the parameters read from the user
	CCircle* C = new CCircle(P1, P2, CircleGfxInfo,circle);
	//Add the circle to the list of figures
	pManager->AddFigure(C);
}
