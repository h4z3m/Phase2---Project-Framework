#ifndef PLAY_FILL_COLOR_H
#define PLAY_FILL_COLOR_H
#include "Action.h"

class Play_FillColorAction :public Action
{
private:
	color RefColor = NULL;
	int CorrectPicks= 0;
	int WrongPicks = 0;

public:
	Play_FillColorAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

#endif	