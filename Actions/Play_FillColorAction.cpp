#include "Play_FillColorAction.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
Play_FillColorAction::Play_FillColorAction(ApplicationManager* pApp) : Action(pApp)
{
}

void Play_FillColorAction::ReadActionParameters()
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
	pOut->PrintMessage("Select all figures with the color " + pOut->getColorName(RefColor));

}

void Play_FillColorAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ReadActionParameters();
	int x, y;
	//Loop until all figures have been picked
	do {

		//Temp figure that the user clicks on
		pIn->GetPointClicked(x, y);
		//Check for a click NOT in an empty place
		if (pManager->GetFigure(x, y) && pIn->DrawArea_ValidClick(x,y,UI.height)) {
			CFigure* TempFig = pManager->GetFigure(x, y);
			//Correct pick AND not a previously picked/hidden figure
			if (RefColor == TempFig->GetFillColorObj() && !TempFig->IsHidden()) {
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
	} while (!(CorrectPicks == (pManager->GetColorFillCount(RefColor) - 1)) && !(pManager->GetFigCount() == (CorrectPicks + WrongPicks)));

	//Printing final score
	pOut->PrintMessage("Final score: " + std::to_string((((float)CorrectPicks - WrongPicks) / CorrectPicks * 100.0)));
}