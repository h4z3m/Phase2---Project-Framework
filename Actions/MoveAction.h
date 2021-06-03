#ifndef MOVE_ACTION_H
#define MOVE_ACTION_H
#include "Action.h"

class MoveAction : public Action {


private:

public:
	MoveAction(ApplicationManager* pApp);

	//Reads  parameters
	virtual void ReadActionParameters();

	//Add  to the ApplicationManager
	virtual void Execute();





};






#endif