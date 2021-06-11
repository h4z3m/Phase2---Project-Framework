#ifndef MOVE_ACTION_H
#define MOVE_ACTION_H
#include "Action.h"
#include "..\ApplicationManager.h"

class MoveAction : public Action {


private:
	Point newPoint;
	Point MainRefrence;

	vector <CFigure*> MovedFigVector;






	Point SecondNewPoint;
	Point ThirdNewPoint;

	Point Refrence1;



	CFigure* MovedFigure;

	CFigure* MovedFiguresList[200];
	GfxInfo FigGfxInfo;

	int numSelRec;
	int numSelTri;


public:
	MoveAction(ApplicationManager* pApp);

	//Reads  parameters
	virtual void ReadActionParameters();

	//Add  to the ApplicationManager
	virtual void Execute();





};






#endif