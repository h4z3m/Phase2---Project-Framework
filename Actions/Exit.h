#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


class Exit : public Action
	{
	public:
		Exit(ApplicationManager* pApp);
		virtual void ReadActionParameters();
		virtual void Execute();
	};

