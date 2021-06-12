#pragma once
#include "Action.h"

class Resize : public Action
{
private:
	string factor_string ;

public:
	Resize(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};



