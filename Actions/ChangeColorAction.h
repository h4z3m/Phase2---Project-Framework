#ifndef CHANGE_COLOR_ACTION_H
#define CHANGE_COLOR_ACTION_H
#include "Action.h"

class ChangeColorAction : public Action
{
private:
	string uChoice="";
	
public:
	ChangeColorAction::ChangeColorAction(ApplicationManager* pApp);
	static void SetFillClrStatus(bool); //Sets the STATIC fill color status for future figure drawings
	virtual void ReadActionParameters();
	virtual void Execute();

};


#endif