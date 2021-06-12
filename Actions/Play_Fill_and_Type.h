#ifndef PLAY_FILL_AND_TYPE_H
#define PLAY_FILL_AND_TYPE_H
#include "Action.h"

class Play_Fill_and_Type :public Action
{
private:
	color RefColor = NULL;
	int CorrectFigsToSelect = 0;
	int PlayFigType = 0;
	int CorrectPicks = 0;
	int WrongPicks = 0;

public:
	Play_Fill_and_Type(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

#endif	