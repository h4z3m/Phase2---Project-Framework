
#include "Copy.h"
Copy::Copy(ApplicationManager* pApp) : Action(pApp)
{}

void Copy::ReadActionParameters()
{
	//Get a Pointer to the Output Interfaces
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("You have Copied the selected figure");

}

void Copy::Execute()
{
	Output* pOut = pManager->GetOutput();

	//This action needs to read some parameters first
	vector <CFigure*> selItems = pManager->GetFigVector();
	bool IsFigSelected = false;
	for (int i = 0;i < selItems.size() ;i++) {
			if (selItems[i] == NULL) {
	
			}
			else {
				IsFigSelected= true;
			}		

	}
	
	if (IsFigSelected != NULL)
	{
		ReadActionParameters();

		pManager->set_Clipboard(selItems);

	}
	else
		pOut->PrintMessage("Firstly, Select a figure");
}


/*Copy::~Copy()
{
}*/