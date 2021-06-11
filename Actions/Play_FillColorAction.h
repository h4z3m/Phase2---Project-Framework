#ifndef PLAY_FILL_COLOR_ACTION_H
#define PLAY_FILL_COLOR_ACTION_H
#include "Action.h"

class Play_FillColorAction :public Action
{
private:
	color RefColor = NULL;
	int CorrectPicks= 0;
	int WrongPicks = 0;

public:
	Play_FillColorAction(ApplicationManager* pApp);

	//Reads circle parameters
	virtual void ReadActionParameters();

	//Add circle to the ApplicationManager
	virtual void Execute();
};

#endif	