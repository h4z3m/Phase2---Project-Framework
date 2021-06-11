#include "AddLineAction.h"
#include "..\Figures\CLine.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddLineAction::AddLineAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddLineAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Line: Click at first point");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Line: Click at second point");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	LineGfxInfo.isFilled = false;	//default is not filled
	LineGfxInfo.isHidden = false;
	//get drawing, filling colors and pen width from the interface
	LineGfxInfo.DrawClr = pOut->getCrntDrawColor();
	LineGfxInfo.FillClr = pOut->getCrntFillColor();
	LineGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();
}

//Execute the action
void AddLineAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//This action needs to read some parameters first
	ReadActionParameters();
	if (pIn->DrawArea_ValidClick(P1.x, P1.y, UI.height) && pIn->DrawArea_ValidClick(P2.x, P2.y, UI.height)) {

		//Create a rectangle with the parameters read from the user
		CLine* L = new CLine(P1, P2, LineGfxInfo);
		L->FigType = line;
		//Add the rectangle to the list of figures
		pManager->AddFigure(L);
	}
	else
	{
		pOut->PrintMessage("ERROR: Please click in the drawing area!");
	}
}
