#pragma once

#include "..\Figures\CFigure.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"
#include "Action.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

void Correct();


class Play_Area : public Action
{
private:
	CFigure* StartFig;
	int CorrectSelections;
	int WrongSelections;
	int GoNext;
	bool PastWrongSlection;
	int WorongCount;
public:
	Play_Area(ApplicationManager* pApp);

	void ReadActionParameters();

	void Execute();

	~Play_Area();

};

