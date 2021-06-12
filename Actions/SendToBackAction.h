#ifndef SEND_TO_BACK_ACTION_H
#define SEND_TO_BACK_ACTION_H
#include "Action.h"
#include "..\Figures\CFigure.h"
class SendToBackAction:public Action
{	private:
	int sel = 0;
	CFigure* newFigList[200];
	public:
	SendToBackAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};
#endif
