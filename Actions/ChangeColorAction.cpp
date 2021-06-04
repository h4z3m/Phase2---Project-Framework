#include "ChangeColorAction.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
ChangeColorAction::ChangeColorAction(ApplicationManager* pApp) : Action(pApp) {
}

void ChangeColorAction::ReadActionParameters() {
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Select the color you want to change, (1) Draw color, (2) Fill color, (3) Background color: ");
	choice = pIn->GetSrting(pOut).at(0);

}
void ChangeColorAction::SetFillClrStatus(bool val) {
	fillClrStatus = val;
}
void ChangeColorAction::Execute() {

	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	string clr="";
	//Let user choose which color to change and choose the color
	switch (stoi(choice))
	{
	case 1:		//Draw color
		pOut->PrintMessage("Choose a Drawing color: 1.Black 2.White 3.Red 4.Green 5.Blue 6.Yellow 7.Aquamarine: ");
		clr = pIn->GetSrting(pOut).at(0);
		switch (stoi(clr)) {
		case black:
			UI.DrawColor = BLACK;
				break;
		case white:
			UI.DrawColor = WHITE;

			break;
		case red:
			UI.DrawColor = RED;
			break;
		case green:
			UI.DrawColor = GREEN;
			break;
		case blue:
			UI.DrawColor = BLUE;
			break;
		case yellow:
			UI.DrawColor = YELLOW;
			break;
		case aqua:
			UI.DrawColor = AQUAMARINE;
			break;
		default:
			UI.DrawColor = BLUE;
			break;
		}
		break;

	case 2:		//Fill color
		pOut->PrintMessage("Choose a Fill color: 1.Black 2.White 3.Red 4.Green 5.Blue 6.Yellow 7.Aquamarine: ");
		clr = pIn->GetSrting(pOut).at(0);

		switch (stoi(clr)) {
		case black:
			UI.FillColor = BLACK;
			SetFillClrStatus(true);
			break;
		case white:
			UI.FillColor = WHITE;
			SetFillClrStatus(true);

			break;
		case red:
			UI.FillColor = RED;
			SetFillClrStatus(true);

			break;
		case green:
			UI.FillColor = GREEN;
			SetFillClrStatus(true);

			break;
		case blue:
			UI.FillColor = BLUE;
			SetFillClrStatus(true);

			break;
		case yellow:
			UI.FillColor = YELLOW;
			SetFillClrStatus(true);

			break;
		case aqua:
			UI.FillColor = AQUAMARINE;
			SetFillClrStatus(true);

			break;
		default:
			UI.FillColor = PINK;
			SetFillClrStatus(true);

			break;
		}
		break;

	case 3:		//Background color
		pOut->PrintMessage("Choose a Background color : 1.Black 2.White 3.Red 4.Green 5.Blue 6.Yellow 7.Aquamarine: ");
		clr = pIn->GetSrting(pOut).at(0);
		switch (stoi(clr)) {
		case black:
			UI.BkGrndColor = BLACK;
			break;
		case white:
			UI.BkGrndColor = WHITE;
			break;
		case red:
			UI.BkGrndColor = RED;
			break;
		case green:
			UI.BkGrndColor = GREEN;
			break;
		case blue:
			UI.BkGrndColor = BLUE;
			break;
		case yellow:
			UI.BkGrndColor = YELLOW;
			break;
		case aqua:
			UI.BkGrndColor = AQUAMARINE;
			break;
			
		default:
			UI.BkGrndColor = LIGHTGOLDENRODYELLOW;
			break;
		}
		break;

	default:
		pOut->ClearStatusBar();
		break;
	}



}