#include "PasteAction.h"
#include "..\Figures/CFigure.h"
#include "..\Figures/CRectangle.h"
#include "..\Figures/CCircle.h"
#include "..\Figures/CTriangle.h"
#include "..\Figures/CLine.h"
#include "..\ApplicationManager.h"
PasteAction::PasteAction(ApplicationManager* pApp) :Action(pApp)
{
}

void PasteAction::ReadActionParameters()
{
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

void PasteAction::Execute()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ReadActionParameters();
	int CCount = pManager->SelectedNumber();
	vector <CFigure*> selItems = pManager->GetFigVector();
	Point Mid = pManager->FiguresMid(selItems, selItems.size());
	if (selItems.size() != Null)
	{
		for (int i = 0; i < (selItems.size()); i++)
		{
			PastedFigure = selItems[i]->Copy();
			PastedFigure->Paste(newPoint, Mid);


			pManager->AddFigure(PastedFigure);
		}
	}
	else
		pOut->PrintMessage("Please Select a figure first.");
}
