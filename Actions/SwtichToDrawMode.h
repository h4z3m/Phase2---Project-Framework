#ifndef SWITCH_DRAW_ACTION_H
#define SWITCH_DRAW_ACTION_H


#include "Action.h"

//Move Action class
class SwitchToDrawAction : public Action {

private:

public:
	SwitchToDrawAction(ApplicationManager* pApp);

	//Reads  parameters
	virtual void ReadActionParameters();

	//Add  to the ApplicationManager
	virtual void Execute();




};



#endif SWITCH_PLAY_ACTION_H
