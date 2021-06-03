#include "SaveAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
SaveAction::SaveAction(ApplicationManager* pApp) :Action(pApp)
{}
void SaveAction::ReadActionParameters() {
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Read filename from user input
	pOut->PrintMessage("Please enter a name for the savefile: ");
	fileName = pIn->GetSrting(pOut);

}
void SaveAction::Execute() {
	Output* pOut = pManager->GetOutput();
	//Read filename from the user
	ReadActionParameters();
	//Pass filename to Appmanager save function
	ofstream saveFile(fileName + ".txt");
	pManager->SaveAll(saveFile);
	pOut->PrintMessage("File saved successfully as: " + fileName + ".txt");

}
