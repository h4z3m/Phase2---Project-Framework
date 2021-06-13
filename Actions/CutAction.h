#pragma once
#include "Action.h"
#include "..\Figures/CFigure.h"
#include"..\ApplicationManager.h"
class CutAction : public Action
{
private:

public:
	CutAction(ApplicationManager* pApp);

	//Reads circle parameters
	virtual void ReadActionParameters();

	//Add circle to the ApplicationManager
	virtual void Execute();
};

