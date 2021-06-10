#pragma once
#include"Action.h"

#include"..\ApplicationManager.h"
#include"..\Figures\CFigure.h"

class SelectAction : public Action
{
private:
	Point P;
	GfxInfo* SelectInfo;
	int Count;
public:
	SelectAction(ApplicationManager* pApp, GfxInfo*);
	virtual void ReadActionParameters();
	virtual void Execute();

};

