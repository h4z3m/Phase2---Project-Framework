#ifndef CHANGE_COLOR_ACTION_H
#define CHANGE_COLOR_ACTION_H


#include "Action.h"
//Add Triangle Action class
class ChangeColorAction : public Action
{
private:
	string choice="";
	enum colors
	{
		no_fill,
		black,
		white,
		red,
		green,
		blue,
		yellow,
		aqua

	};
public:
	ChangeColorAction::ChangeColorAction(ApplicationManager* pApp);
	//Reads triangle parameters
	virtual void ReadActionParameters();

	//Add triangle to the ApplicationManager
	virtual void Execute();

};


#endif