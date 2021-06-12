#pragma once
#include "Action.h"
class zoom : public Action
{
private:
	string factor_string;
	int key;
public:
	zoom(ApplicationManager* pApp,int i);
	virtual void ReadActionParameters();
	virtual void Execute();
};





