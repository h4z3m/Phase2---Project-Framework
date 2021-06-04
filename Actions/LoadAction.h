#ifndef LOAD_ACTION_H
#define LOAD_ACTION_H
#include"Action.h"
class LoadAction : public Action {
private:
	ifstream file;
	string fileName;
	GfxInfo defaultGfxInfo;
	Point defaultPoint;
public:
	LoadAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};

#endif // !LOAD_ACTION_H