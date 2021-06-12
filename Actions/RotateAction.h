#pragma once

#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


class RotateAction : public Action
{
	CFigure* deleted;
public:
	RotateAction(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();
};

