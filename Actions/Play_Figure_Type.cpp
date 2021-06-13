#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"
#include "Play_Figure_Type.h"
Play_Figure_Type::Play_Figure_Type(ApplicationManager* pApp) : Action(pApp)
{}

void Play_Figure_Type::ReadActionParameters()
{
	//User click coordinates
	int x, y;
	//Get the first figure the user clicks so we can use its shape
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Play by figure type mode: Click a figure to start.");
	pIn->GetPointClicked(x, y);

	//Send point to application manager to find which figure was clicked
	CFigure* RefFig = pManager->GetFigure(x, y);

	//If user doesn't click on a figure
	while ((RefFig = pManager->GetFigure(x, y)) == NULL) {
		pOut->PrintMessage("ERROR: Please click on a figure");
		pIn->GetPointClicked(x, y);
	}
	//Get reference fill color
	RefFig = pManager->GetFigure(x, y);

	RefFig->FigType;
	RefFig->SetHidden(true); //Hide reference figure
	pManager->UpdateInterface(); //Updated with hidden figure
	pOut->PrintMessage("YAY!!! Now select every " + RefFig->GetFigName());
	PlayFigType = RefFig->FigType;
	switch (PlayFigType)
	{
	case line:
		CorrectFigsToSelect = pManager->GetLineCountWColor(NULL);
		break;
	case rectangle:
		CorrectFigsToSelect = pManager->GetRectCountWColor(NULL);
		break;
	case triangle:
		CorrectFigsToSelect = pManager->GetTriCountWColor(NULL);

		break;
	case circle:
		CorrectFigsToSelect = pManager->GetCirCountWColor(NULL);

		break;
	}
}

void Play_Figure_Type::Execute()
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
		if (pManager->GetFigure(x, y) && pIn->DrawArea_ValidClick(x, y, UI.height)) {
			CFigure* TempFig = pManager->GetFigure(x, y);
			//Correct pick AND not a previously picked/hidden figure
			if (TempFig->FigType == PlayFigType && !TempFig->IsHidden()) {
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
	} while (!(CorrectPicks + 1 == (CorrectFigsToSelect)) && !(pManager->GetFigCount() == (CorrectPicks + WrongPicks)) && !(CorrectFigsToSelect == 1));

	//Printing final score
	pOut->PrintMessage("You scored: " + std::to_string(CorrectPicks) + "/" + std::to_string(WrongPicks + CorrectPicks));
	pManager->UnhideAllFigs();

}