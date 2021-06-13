#include "zoom.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
zoom::zoom(ApplicationManager* pApp,int i) :Action(pApp),key(i)
{}

void  zoom::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	if (key == 1){
		pOut->PrintMessage("Zooming in");
	}
	else if (key == 2) {
		pOut->PrintMessage("Zooming out");
	}

}

void zoom::Execute() {
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	if (key == 1) {
		pManager->zooming(1.6);
		pOut->ClearStatusBar();
	}
	else if (key == 2)
	{
		pManager->zooming(0.625);
		pOut->ClearStatusBar();
	}
	else {
		pOut->ClearStatusBar();
		pOut->PrintMessage("Sorry, undefined reply ");
	}

}
