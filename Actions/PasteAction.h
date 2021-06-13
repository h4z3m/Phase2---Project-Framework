#ifndef PASTE_ACTION_H
#define PASTE_ACTION_H
#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
class PasteAction:public Action
{
private:
	Point newPoint;
	Point MainRefrence;

	vector <CFigure*> MovedFigVector;

	Point SecondNewPoint;
	Point ThirdNewPoint;

	Point Refrence1;



	CFigure* PastedFigure;

	CFigure* MovedFiguresList[200];
	GfxInfo FigGfxInfo;

	int numSelRec;
	int numSelTri;
public:
	PasteAction(ApplicationManager* pApp);

	//Reads circle parameters
	virtual void ReadActionParameters();

	//Add circle to the ApplicationManager
	virtual void Execute();


};
#endif 
