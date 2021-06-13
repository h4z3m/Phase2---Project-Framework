#ifndef MOVE_ACTION_H
#define MOVE_ACTION_H
#include "Action.h"
#include "..\ApplicationManager.h"

class MoveAction : public Action {


private:
	Point newPoint;
	Point MainRefrence;
	vector <CFigure*> MovedFigVector;
	bool SelectedFlag;
	GfxInfo FigGfxInfo;
public:
	MoveAction(ApplicationManager* pApp);

	//Reads  parameters
	virtual void ReadActionParameters();

	//Add  to the ApplicationManager
	virtual void Execute();

};
#endif