#ifndef CHANGE_COLOR_ACTION_H
#define CHANGE_COLOR_ACTION_H


#include "Action.h"
//Add Triangle Action class
class ChangeColorAction : public Action
{
private:
	string choice="";
	
public:
	ChangeColorAction::ChangeColorAction(ApplicationManager* pApp);
	//Reads triangle parameters
	static void SetFillClrStatus(bool);
	virtual void ReadActionParameters();

	//Add triangle to the ApplicationManager
	virtual void Execute();

};


#endif