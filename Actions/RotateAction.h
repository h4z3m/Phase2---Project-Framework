#pragma once


#include "Action.h"
#include "..\ApplicationManager.h"

class RotateAction : public Action
{

private:


	bool SelectedFlag;



	GfxInfo FigGfxInfo;


public:
	RotateAction(ApplicationManager* pApp);

	//Reads  parameters
	virtual void ReadActionParameters();

	//Add  to the ApplicationManager
	virtual void Execute();


};

