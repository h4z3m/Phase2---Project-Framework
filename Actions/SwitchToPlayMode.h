#ifndef SWITCH_PLAY_ACTION_H
#define SWITCH_PLAY_ACTION_H


#include "Action.h"

//Move Action class
class SwitchToPlayAction : public Action {

private:

public:
	SwitchToPlayAction(ApplicationManager* pApp);

	//Reads  parameters
	virtual void ReadActionParameters();

	//Add  to the ApplicationManager
	virtual void Execute();




};



#endif SWITCH_PLAY_ACTION_H
