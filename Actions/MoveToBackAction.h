#ifndef MOVE_TO_BACK_ACTION
#define MOVE_TO_BACK_ACTION
#include "Action.h"
#include "..\Figures\CFigure.h"
class MoveToBackAction:public Action
{	private:
	int sel = 0;
	CFigure* newFigList[200];
	public:
	MoveToBackAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};
#endif
