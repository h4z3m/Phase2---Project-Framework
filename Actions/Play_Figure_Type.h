#pragma once
#include "Action.h"

class Play_Figure_Type : public Action
{
private:
	int PlayFigType = 0;
	int CorrectFigsToSelect = 0;
	int CorrectPicks = 0;
	int WrongPicks = 0;

public:
	CFigure* RefType;
	Play_Figure_Type(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};