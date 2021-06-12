#ifndef BRING_TO_FRONT_ACTION_H
#define BRING_TO_FRONT_ACTION_H
#include "Action.h"
#include "..\Figures\CFigure.h"
class BringToFrontAction :public Action
{
private:
	int sel = 0;
	CFigure* newFigList[200];
public:
	BringToFrontAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};
#endif
