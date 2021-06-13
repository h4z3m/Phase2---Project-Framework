#include "Resize.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
Resize::Resize(ApplicationManager* pApp) :Action(pApp)
{}

void  Resize::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Select the factor you want to multiply, (1) for 4x, (2) for 2x, (3) for 1/2x, (4) for 1/4x: ");
	factor_string = pIn->GetSrting(pOut).at(0);

}

void Resize::Execute() {
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int factor = stoi(factor_string);
	if (factor == 1) {
		pManager->Changesize(4);
		pOut->ClearStatusBar();
	}
	else if (factor == 2)
	{
		pManager->Changesize(2);
		pOut->ClearStatusBar();
	}
	else if (factor == 3)
	{
		pManager->Changesize(0.5);
		pOut->ClearStatusBar();
	}
	else if (factor == 4)
	{
		pManager->Changesize(0.25);
		pOut->ClearStatusBar();
	}
	else {
		pOut->ClearStatusBar();
		pOut->PrintMessage("Sorry,you undefined reply ");
	}
	
}
