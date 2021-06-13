#ifndef SEND_TO_BACK_ACTION_H
#define SEND_TO_BACK_ACTION_H
#include "Action.h"
#include "..\Figures\CFigure.h"
class SendToBackAction:public Action
{	private:
	public:
	SendToBackAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};
#endif
