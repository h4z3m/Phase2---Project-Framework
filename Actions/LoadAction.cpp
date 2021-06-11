#include "LoadAction.h"
#include "SaveAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CTriangle.h"
/*///////////////////
TODO:If there is a graph already drawn on the drawing area and the load operation is chosen, the 
application must ask the user if he / she wants to save the current graph.Then, any needed
cleanup of the current drawn graphand load the new one
*////////////////////
LoadAction::LoadAction(ApplicationManager* pApp) : Action(pApp)
{
}

void LoadAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	defaultPoint = { 0,0 };
	if(pManager->isGraphEmpty()){//Read filename from user input
		pOut->PrintMessage("Please enter a graph savefile to load from: ");
		fileName = pIn->GetSrting(pOut);
		//Set default graphics info
		defaultGfxInfo.isFilled = false;
		defaultGfxInfo.BorderWdth = pOut->getCrntPenWidth();
		defaultGfxInfo.DrawClr = pOut->getCrntDrawColor();
		defaultGfxInfo.FillClr = pOut->getCrntFillColor();
		return;
	}
	else {
		pOut->PrintMessage("Do you want to save the current graph before loading? (Y/N)");
		string c = pIn->GetSrting(pOut);
		if (c == "Y") {
			pManager->ExecuteAction(SAVE);
		}
		//Delete all figures
		pManager->DeleteAllFigs();
		//Read filename from user input
		pOut->PrintMessage("Please enter a graph savefile to load from: ");
		fileName = pIn->GetSrting(pOut);
		//Set default graphics info
		defaultGfxInfo.isFilled = false;
		defaultGfxInfo.BorderWdth = pOut->getCrntPenWidth();
		defaultGfxInfo.DrawClr = pOut->getCrntDrawColor();
		defaultGfxInfo.FillClr = pOut->getCrntFillColor();
	}
}

void LoadAction::Execute()
{
	ReadActionParameters();
	
	Output* pOut = pManager->GetOutput();
	string stline;
	// Open file and search for figure strings then create a corresponding objects and load its data
	// Data is passed as a stringstream to load virtual fn. (whole line is passed)
	file.open(fileName);
	if (file.is_open()) {
		while (getline(file, stline)) {
			if (stline.find("CIRCLE") != string::npos) {
				stringstream ss(stline);
				int radius;
				CCircle* C = new CCircle(defaultPoint, defaultPoint, defaultGfxInfo,circle);
				C->Load(file, pOut, ss);
				pManager->AddFigure(C);
			}
			else if (stline.find("RECTANGLE") != string::npos) {
				stringstream ss(stline);
				CRectangle* R = new CRectangle(defaultPoint, defaultPoint, defaultGfxInfo,rectangle);
				R->Load(file, pOut, ss);
				pManager->AddFigure(R);
			}
			else if (stline.find("LINE") != string::npos) {
				stringstream ss(stline);
				CLine* L = new CLine(defaultPoint, defaultPoint, defaultGfxInfo,line);
				L->Load(file, pOut, ss);
				pManager->AddFigure(L);
			}
			else if (stline.find("TRIANGLE") != string::npos) {
				stringstream ss(stline);
				CTriangle* T = new CTriangle(defaultPoint, defaultPoint, defaultPoint, defaultGfxInfo, triangle);
				T->Load(file, pOut, ss);
				pManager->AddFigure(T);
			}
			//First line which contains UI colors (draw,fill,background)
			else {
				string DrawClr;
				string FillClr;
				string BkGClr;
				stringstream ss(stline);
				ss >> DrawClr >> FillClr >> BkGClr;
				UI.DrawColor = pOut->getColorObj(DrawClr);
				UI.FillColor = pOut->getColorObj(FillClr);
				UI.BkGrndColor = pOut->getColorObj(BkGClr);

			}
		}
		file.close();
	}
}
