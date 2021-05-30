#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\AddCircleAction.h"
#include"Actions\AddTriangleAction.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		pAct = new AddRectAction(this);
		break;

	case DRAW_LINE:
		pAct = new AddLineAction(this);

		break;


	case DRAW_CIRC:
		pAct = new AddCircleAction(this);
		break;
	case DRAW_TRI:
		pAct = new AddTriangleAction(this);
		break;
	case CHNG_FILL_CLR:
		break;
	case CHNG_BK_CLR:
		break;
	case CHNG_DRAW_CLR:
		break;
	case DEL:
		break;
	case MOVE:
		break;
	case RESIZE:
		break;
	case ROTATE:
		break;
	case SEND_BACK:
		break;
	case BRNG_FRNT:
		break;
	case SAVE:
		break;
	case LOAD:
		break;
	case UNDO:
		break;
	case REDO:
		break;
	case SELECT_FIGURE:
		break;
	case ZOOM_IN:
		break;
	case ZOOM_OUT:
		break;
	case COPY:
		break;
	case CUT:
		break;
	case PASTE:
		break;
	case Figure_Type:
		break;
	case Figure_Fill_Color:
		break;
	case Figure_Fill_Type:
		break;
	case Figure_Area:
		break;
	case DRAWING_AREA:
		break;
	case GAMING_AREA:
		break;
	case EMPTY:
		break;
	case TO_DRAW:
		break;
	case TO_PLAY:
		break;
	case EXIT:
		///create ExitAction here

		break;
	case STATUS:	//a click on the status bar ==> no action
		return;
	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
		FigList[FigCount++] = pFig;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	///Add your code here to search for a figure given a point x,y	

	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input* ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output* ApplicationManager::GetOutput() const
{
	return pOut;
}
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;

}
