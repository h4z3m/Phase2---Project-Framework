#pragma once

#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


class Delete :
	public Action
{
	CFigure* deleted;
public:

	Delete(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();


};

