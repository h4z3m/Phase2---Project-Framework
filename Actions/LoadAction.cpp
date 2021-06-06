#include "LoadAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CTriangle.h"
LoadAction::LoadAction(ApplicationManager* pApp) : Action(pApp)
{
}

void LoadAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	defaultPoint = { 0,0 };

	//Read filename from user input
	pOut->PrintMessage("Please enter a graph savefile to load from: ");
	fileName = pIn->GetSrting(pOut);
	//Set default graphics info
	defaultGfxInfo.isFilled = false;
	defaultGfxInfo.BorderWdth = pOut->getCrntPenWidth();
	defaultGfxInfo.DrawClr = pOut->getCrntDrawColor();
	defaultGfxInfo.FillClr = pOut->getCrntFillColor();
}

void LoadAction::Execute()
{
	ReadActionParameters();
	
	Output* pOut = pManager->GetOutput();
	string line;
	// Open file and search for figure strings then create a corresponding objects and load its data
	// Data is passed as a stringstream to load virtual fn. (whole line is passed)
	file.open(fileName);
	if (file.is_open()) {
		while (getline(file, line)) {
			if (line.find("CIRCLE") != string::npos) {
				stringstream ss(line);
				int radius;
				CCircle* C = new CCircle(defaultPoint, defaultPoint, defaultGfxInfo);
				C->Load(file, pOut, ss);
				pManager->AddFigure(C);
			}
			else if (line.find("RECTANGLE") != string::npos) {
				stringstream ss(line);
				CRectangle* R = new CRectangle(defaultPoint, defaultPoint, defaultGfxInfo);
				R->Load(file, pOut, ss);
				pManager->AddFigure(R);
			}
			else if (line.find("LINE") != string::npos) {
				stringstream ss(line);
				CLine* L = new CLine(defaultPoint, defaultPoint, defaultGfxInfo);
				L->Load(file, pOut, ss);
				pManager->AddFigure(L);
			}
			else if (line.find("TRIANGLE") != string::npos) {
				stringstream ss(line);
				CTriangle* T = new CTriangle(defaultPoint, defaultPoint, defaultPoint, defaultGfxInfo);
				T->Load(file, pOut, ss);
				pManager->AddFigure(T);
			}
			//First line which contains UI colors (draw,fill,background)
			else {
				string DrawClr;
				string FillClr;
				string BkGClr;
				stringstream ss(line);
				ss >> DrawClr >> FillClr >> BkGClr;
				UI.DrawColor = pOut->getColorObj(DrawClr);
				UI.FillColor = pOut->getColorObj(FillClr);
				UI.BkGrndColor = pOut->getColorObj(BkGClr);

			}
		}
		file.close();
	}
}
