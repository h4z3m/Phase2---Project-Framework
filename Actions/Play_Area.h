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
	Play_Area::Play_Area(ApplicationManager* pApp);

	void Play_Area::ReadActionParameters();

	void Play_Area::Execute();
};

