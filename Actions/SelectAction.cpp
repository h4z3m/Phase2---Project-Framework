#include "SelectAction.h"

SelectAction::SelectAction(ApplicationManager* pApp, GfxInfo* SelGfxInfo)
	: Action(pApp), SelectInfo(SelGfxInfo)
{}
void SelectAction::ReadActionParameters()
{
	//We need a pointer to the input and output class as a reference
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();



	//select a point on the figure wanted
	pOut->PrintMessage("Select a figure ");

	pIn->GetPointClicked(P.x, P.y);

}


void SelectAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	// condition to check if the point clicked is in a valid area
	if (P.y < UI.StatusBarHeight || P.y > UI.height - UI.StatusBarHeight)
	{
		bool flag = false; 
		pOut->PrintMessage("Try again, in a valid area");
		while (!flag)
		{
			pIn->GetPointClicked(P.x, P.y); 
			if (!(P.y < UI.StatusBarHeight || P.y > UI.height - UI.StatusBarHeight))
				flag = 1;
		}
	}
	pOut->ClearStatusBar();

	CFigure* fig = pManager->GetFigure(P.x, P.y);
	Count = pManager->SelectedNumber();

	if (fig != NULL)
	{
		if (fig->IsSelected())
		{
			fig->SetSelected(false);
			//////////////********** GILANY'S PART ************//////////////////
			pManager->MakeItUnSelected(fig);
			//////////////********** GILANY'S PART ************//////////////////

		}
		else
		{
			
			fig->SetSelected(true);
			string x = fig->PrintInfo(pOut);

			if (Count <=1)
			{
				pOut->PrintMessage(x);
				//////////////********** GILANY'S PART ************//////////////////
				pManager->MakeItSelected(fig);
				//////////////********** GILANY'S PART ************//////////////////


			}
			else
			{
				string s = to_string(Count);
				pOut->PrintMessage("Number of Selected figures: " + s);
				//////////////********** GILANY'S PART ************//////////////////
				pManager->MakeItSelected(fig);
				//////////////********** GILANY'S PART ************//////////////////


			}
			
		}

	}
	
}
