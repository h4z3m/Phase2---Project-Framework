#include "Play_Fill_and_Type.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
Play_Fill_and_Type::Play_Fill_and_Type(ApplicationManager* pApp) : Action(pApp)
{
}

void Play_Fill_and_Type::ReadActionParameters()
{

	//User click coordinates
	int x, y;
	//Get the first figure the user clicks so we can use its color
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Play by figure fill color mode: Click a figure to start.");
	pIn->GetPointClicked(x, y);

	//Send point to application manager to find which figure was clicked
	CFigure* RefFig = pManager->GetFigure(x, y);

	//If user doesn't click on a figure
	while ((RefFig = pManager->GetFigure(x, y)) == NULL || !RefFig->IsFilled()) {
		pOut->PrintMessage("ERROR: Please click on a FILLED figure");
		pIn->GetPointClicked(x, y);
	}
	//Get reference fill color
	RefFig = pManager->GetFigure(x, y);
	RefColor = RefFig->GetFillColorObj();
	RefFig->SetHidden(true); //Hide reference figure
	pManager->UpdateInterface(); //Updated with hidden figure
	pOut->PrintMessage("Select all " + RefFig->GetFigName() + "s" + " with the color " + pOut->getColorName(RefColor));
	PlayFigType = RefFig->FigType;
	switch (PlayFigType) {
	case line:
		CorrectFigsToSelect = pManager->GetLineCountWColor(RefColor);
		break;
	case rectangle:
		CorrectFigsToSelect = pManager->GetRectCountWColor(RefColor);

		break;
	case triangle:
		CorrectFigsToSelect = pManager->GetTriCountWColor(RefColor);

		break;
	case circle:
		CorrectFigsToSelect = pManager->GetCirCountWColor(RefColor);

		break;
	}
}

void Play_Fill_and_Type::Execute()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ReadActionParameters();
	int x, y;
	//Loop until all figures have been picked
	do {
		//For unique figures
		if (CorrectFigsToSelect == 1) { break; }

		//Temp figure that the user clicks on
		pIn->GetPointClicked(x, y);
		//Check for a click NOT in an empty place
		if (pManager->GetFigure(x, y) && pIn->DrawArea_ValidClick(x, y, UI.height)) {
			CFigure* TempFig = pManager->GetFigure(x, y);
			//Correct pick AND not a previously picked/hidden figure
			if (RefColor == TempFig->GetFillColorObj() && !TempFig->IsHidden() && TempFig->FigType == PlayFigType) {
				++CorrectPicks;
				TempFig->SetHidden(true);
			}
			//Wrong pick OR a click on an empty place
			else if (!TempFig->IsHidden()) {
				++WrongPicks;
				TempFig->SetHidden(true);
			}
			pManager->UpdateInterface(); //Updated with hidden figures

			//Print correct & wrong picks for the user
			pOut->PrintMessage("Correct picks: " + std::to_string(CorrectPicks) + " Wrong picks: " + std::to_string(WrongPicks));
		}
		//+1 to include the Reference figure click
	} while (!(CorrectPicks + 1 == (CorrectFigsToSelect)) && !(pManager->GetFigCount() == (CorrectPicks + WrongPicks)) && !(CorrectFigsToSelect == 1));

	//Printing final score
	//In case it was a unique figure e.g. the only blue rectangle
	if (CorrectFigsToSelect == 1) {
		pOut->PrintMessage("Final score: 100%, it was a unique figure.");
	}
	else {
		//+1 to include the Reference figure click
		pOut->PrintMessage("Final score: " + std::to_string((((float)CorrectPicks+1 - WrongPicks) / CorrectFigsToSelect * 100.0))+" %");
	}
}
