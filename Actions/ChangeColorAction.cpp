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
	try {
		uChoice = pIn->GetSrting(pOut).at(0);
	}
	catch (...) {
		pOut->PrintMessage("Please select the color you want to change !");
	}
}

void ChangeColorAction::SetFillClrStatus(bool val) {
	fillClrStatus = val;
}

void ChangeColorAction::Execute() {

	ReadActionParameters();

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	string clr = "";

	//Let user choose which color to change and choose the color
	if (uChoice == "") {
	}
	else {
		try {
			switch (stoi(uChoice))
			{
			case 1:		//Draw color
				pOut->PrintMessage("Choose a Drawing color: 1.Black 2.White 3.Red 4.Green 5.Blue 6.Yellow 7.Aquamarine (0 for default): ");
				try {
					clr = pIn->GetSrting(pOut).at(0);
				}
				catch (...) {
					pOut->PrintMessage("Please select the color you want to change !");
				}
				if (clr == "") {}
				else {
					switch (stoi(clr)) {
					case black:
						UI.DrawColor = BLACK;
						pOut->PrintMessage("Draw color changed to: Black");
						break;
					case white:
						UI.DrawColor = WHITE;
						pOut->PrintMessage("Draw color changed to: White");

						break;
					case red:
						UI.DrawColor = RED;
						pOut->PrintMessage("Draw color changed to: Red");

						break;
					case green:
						UI.DrawColor = GREEN;
						pOut->PrintMessage("Draw color changed to: Green");

						break;
					case blue:
						UI.DrawColor = BLUE;
						pOut->PrintMessage("Draw color changed to: Blue");

						break;
					case yellow:
						UI.DrawColor = YELLOW;
						pOut->PrintMessage("Draw color changed to: Yellow");

						break;
					case aqua:
						UI.DrawColor = AQUAMARINE;
						pOut->PrintMessage("Draw color changed to: Aquamarine");

						break;
					default:
						UI.DrawColor = BLUE;
						pOut->PrintMessage("Draw color changed to: Blue");

						break;
					}
					break;
				}
			case 2:		//Fill color
				pOut->PrintMessage("Choose a Fill color: 1.Black 2.White 3.Red 4.Green 5.Blue 6.Yellow 7.Aquamarine (0 for default): ");
				clr = pIn->GetSrting(pOut).at(0);
				try {
					clr = pIn->GetSrting(pOut).at(0);
				}
				catch (...) {
					pOut->PrintMessage("Please select the color you want to change !");
				}
				if (clr == "") {}
				else
				{
					switch (stoi(clr)) {
					case black:
						UI.FillColor = BLACK;
						SetFillClrStatus(true);
						pOut->PrintMessage("Fill color changed to: Black");
						break;
					case white:
						UI.FillColor = WHITE;
						SetFillClrStatus(true);
						pOut->PrintMessage("Fill color changed to: White");

						break;
					case red:
						UI.FillColor = RED;
						SetFillClrStatus(true);
						pOut->PrintMessage("Fill color changed to: Red");
						break;
					case green:
						UI.FillColor = GREEN;
						SetFillClrStatus(true);
						pOut->PrintMessage("Fill color changed to: Green");
						break;
					case blue:
						UI.FillColor = BLUE;
						SetFillClrStatus(true);
						pOut->PrintMessage("Fill color changed to: Blue");
						break;
					case yellow:
						UI.FillColor = YELLOW;
						SetFillClrStatus(true);
						pOut->PrintMessage("Fill color changed to: Yellow");
						break;
					case aqua:
						UI.FillColor = AQUAMARINE;
						SetFillClrStatus(true);
						pOut->PrintMessage("Fill color changed to: Aquamarine");
						break;
					default:
						UI.FillColor = GREEN;
						SetFillClrStatus(false);
						pOut->PrintMessage("Fill color changed to: Green");
						break;
					}
					break;
				}
			case 3:		//Background color
				pOut->PrintMessage("Choose a Background color : 1.Black 2.White 3.Red 4.Green 5.Blue 6.Yellow 7.Aquamarine (0 for default): ");
				clr = pIn->GetSrting(pOut).at(0);
				try {
					clr = pIn->GetSrting(pOut).at(0);
				}
				catch (...) {
					pOut->PrintMessage("Please select the color you want to change !");
				}
				if (clr == "") {}
				else {
					switch (stoi(clr)) {
					case black:
						UI.BkGrndColor = BLACK;
						pOut->PrintMessage("Background color changed to: Black");
						break;
					case white:
						UI.BkGrndColor = WHITE;
						pOut->PrintMessage("Background color changed to: White");
						break;
					case red:
						UI.BkGrndColor = RED;
						pOut->PrintMessage("Background color changed to: Red");
						break;
					case green:
						UI.BkGrndColor = GREEN;
						pOut->PrintMessage("Background color changed to: Green");
						break;
					case blue:
						UI.BkGrndColor = BLUE;
						pOut->PrintMessage("Background color changed to: Blue");
						break;
					case yellow:
						UI.BkGrndColor = YELLOW;
						pOut->PrintMessage("Background color changed to: Yellow");
						break;
					case aqua:
						UI.BkGrndColor = AQUAMARINE;
						pOut->PrintMessage("Background color changed to: Aquamarine");
						break;

					default:
						UI.BkGrndColor = LIGHTGOLDENRODYELLOW;
						pOut->PrintMessage("Background color changed to: LIGHTGOLDENRODYELLOW");
						break;
					}
					break;
				}
			default:
				pOut->ClearStatusBar();
				break;
			}
		}
		catch (...) {
			pOut->PrintMessage("Please select the color you want to change !");
		}
	}

}