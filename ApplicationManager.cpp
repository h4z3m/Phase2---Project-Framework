//test kda allahomsaly3alanby


#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\AddCircleAction.h"
#include "Actions\AddTriangleAction.h"
#include "Actions\SaveAction.h"
#include "Actions\LoadAction.h"
#include "Actions\ChangeColorAction.h"
#include "Actions\SelectAction.h"
#include "Actions\Delete.h"
#include "Actions\MoveAction.h"
#include "Actions\SwitchToPlayMode.h"
#include "Actions\SwitchToDrawAction.h"
#include "Actions\Play_FillColorAction.h"
#include "Actions\Play_Area.h"
#include "Figures\CFigure.h"
#include "Figures\CRectangle.h"
#include "Figures\CCircle.h"
#include "Figures\CTriangle.h"
#include "Figures\CLine.h"

bool Action::fillClrStatus = false;
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

	MoveLoopCount = 0;
	RecAreaCount=0;
	TriAreaCount=0;
	LinAreaCount=0;
	CirAreaCount=0;

}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();
}
void ApplicationManager::SaveAll(ofstream& saveFile) {
	//Check if file is open before appending line to avoid runtime error
	if (saveFile.is_open()) {
		SaveGraphColors(saveFile);
		//Save each fig. using virtual function
		for (int i = 0; i < FigCount; i++) {
			FigList[i]->Save(saveFile, pOut);
		}
	}

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

	case CHNG_DRAW_CLR:
		pAct = new ChangeColorAction(this);
		break;

	case DEL:
		pAct = new Delete(this);
		break;

	case MOVE:
		pAct = new MoveAction(this);
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
		pAct = new SaveAction(this);
		break;

	case LOAD:
		pAct = new LoadAction(this);
		break;

	case UNDO:
		break;

	case REDO:
		break;

	case SELECT_FIGURE:
		pAct = new SelectAction(this, &SelectInfo);
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
		pAct = new Play_FillColorAction(this);
		break;

	case Figure_Fill_Type:
		break;

	case Figure_Area:
		pAct = new Play_Area(this);
		break;

	case DRAWING_AREA:
		break;

	case GAMING_AREA:
		break;

	case EMPTY:
		break;

	case TO_DRAW:
		pAct = new SwitchToDrawAction(this);
		break;

	case TO_PLAY:
		pAct = new SwitchToPlayAction(this);
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
	pFig->SetID(rID++);
	if (FigCount < MaxFigCount)
		FigList[FigCount++] = pFig;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL

	/////////////Ali////////////////////////////////
	for (int i = FigCount - 1; i >= 0; i--)
		if (FigList[i]->Fig(x, y))
		{
			return FigList[i];
		}
	/////////////Ali////////////////////////////////
	return NULL;
}
int ApplicationManager::GetLineCount()
{
	int count = 0;
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->FigType == line)
			count++;
	}
	return count;
}
int ApplicationManager::GetCirCount()
{
	int count = 0;
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->FigType == circle)
			count++;
	}
	return count;
}
int ApplicationManager::GetTriCount()
{
	int count = 0;
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->FigType == triangle)
			count++;
	}
	return count;
}
int ApplicationManager::GetRectCount()
{
	int count = 0;
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->FigType == rectangle)
			count++;
	}
	return count;
}
int ApplicationManager::GetColorFillCount(color clr)
{
	int count = 0;
	for (int i = 0; i < FigCount ; i++) {
		if (clr == FigList[i]->GetFillColorObj() )
			count++;
	}
	return count;
}
//Check if graph is empty
bool ApplicationManager::isGraphEmpty() {
	for (int i = 0; i < MaxFigCount; i++) {
		if (FigList[i] == NULL) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}


//////////////********** GILANY'S PART ************//////////////////

//ADD THE SELECTED FIGURE TO THE LIST OF SELECTED FIGURES 
void ApplicationManager::MakeItSelected(CFigure* fig) {

	FigVector.push_back(fig);
}

//DELETE THE SELECTED FIGURE FROM THE LIST OF SELECTED FIGURES 
void ApplicationManager::MakeItUnSelected(CFigure* fig) {

	auto it = find(FigVector.begin(), FigVector.end(), fig);
	int index;
	if (it != FigVector.end())
	{

		// calculating the index of fig
		index = it - FigVector.begin();
	}

	FigVector.erase(FigVector.begin() + index);
}

//MAKE A REFRENCE POINT OF THE FIRST SELECTED FIGURE 
//TO MOVE THE OTHER SELECTED FIGURES WITH RESPECT TO IT
//IF YOU UNSELECT THE FIRST FIGURE, THE POINT OF THE OTHER FIGURE WILL BE TAKEN AS A REFRENCE 
Point ApplicationManager::MakeRefrencePoint() {

	CRectangle* rect = dynamic_cast<CRectangle*> (FigVector[0]);
	CLine* line = dynamic_cast<CLine*> (FigVector[0]);
	CTriangle* tri = dynamic_cast<CTriangle*> (FigVector[0]);
	CCircle* cir = dynamic_cast<CCircle*> (FigVector[0]);

	//IF THE FIGURE IS RECTANGLE
	if (rect != NULL)
		return rect->GetRecHighPoint();
	//IF THE FIGURE IS RECTANGLE
	else if (line != NULL)
		return line->GetLinHighPoint();
	//IF THE FIGURE IS TRIANGLE
	else if (tri != NULL)
		return tri->GetTriHighPoint();
	//IF THE FIGURE IS CIRCLE
	else
		return cir->GetCirHighPoint();

}

//IF THE FIGURE IS RECTANGLE

vector <CFigure*> ApplicationManager::GetFigVector() {

	if (FigVector.size() == 0)
		pOut->PrintMessage("Select a figure first ya haywan");
	else
		return FigVector;
}


CFigure* ApplicationManager::MoveLoop() {
	while ( MoveLoopCount < FigVector.size() ) {

		//CHECK THE TYPE OF THE FIGURE 
		CRectangle* rect = dynamic_cast<CRectangle*> (FigVector[MoveLoopCount]);
		CLine* line = dynamic_cast<CLine*> (FigVector[MoveLoopCount]);
		CTriangle* tri = dynamic_cast<CTriangle*> (FigVector[MoveLoopCount]);
		CCircle* cir = dynamic_cast<CCircle*> (FigVector[MoveLoopCount]);

		//IF THE FIGURE IS RECTANGLE
		if (rect != NULL) {
			MoveLoopCount++;

			return rect;

		}

		//IF THE FIGURE IS TRIANGLE
		if (tri != NULL) {
			MoveLoopCount++;

			return tri;

		}

		//IF THE FIGURE IS LINE
		if (line != NULL) {
			MoveLoopCount++;

			return line;

		}

		if (cir != NULL) {
			MoveLoopCount++;

			return cir;

		}

	}
}

int ApplicationManager::GetVectorSize() {
	return FigVector.size();
}

void ApplicationManager::ResetCount() {
	MoveLoopCount = 0;
}




bool ApplicationManager::CheckSmallest(CFigure* fig) {
	CRectangle* rect = dynamic_cast<CRectangle*> (fig);
	CLine* line = dynamic_cast<CLine*> (fig);
	CTriangle* tri = dynamic_cast<CTriangle*> (fig);
	CCircle* cir = dynamic_cast<CCircle*> (fig);



	//IF THE FIGURE IS RECTANGLE
	if (rect != NULL) {
		if (fig->GetArea() == RecAreas[0])
			return true;
		else
			return false;
	}

	//IF THE FIGURE IS TRIANGLE
	else if (tri != NULL) {
			if (fig->GetArea() == TriAreas[0])
				return true;
			else
				return false;
	}

	//IF THE FIGURE IS LINE
	else if (line != NULL) {
		if (fig->GetArea() == LinAreas[0])
			return true;
		else
			return false;

	}

	else if (cir != NULL) {
		if (fig->GetArea() == CirAreas[0])
			return true;
		else
			return false;
	}


}



void ApplicationManager::CreateRecAreasVector() {

	for (int i = 0; i < FigCount; i++) {
		CRectangle* P = dynamic_cast<CRectangle*> (FigList[i]);
		if(P != NULL)
		RecAreas.push_back(FigList[i]->GetArea());
	}

	sort(RecAreas.begin(), RecAreas.end());

}

void ApplicationManager::CreateTriAreasVector() {

	for (int i = 0; i < FigCount; i++) {
		CTriangle* P = dynamic_cast<CTriangle*> (FigList[i]);
		if (P != NULL)
			TriAreas.push_back(FigList[i]->GetArea());
	}

	sort(TriAreas.begin(), TriAreas.end());

}

void ApplicationManager::CreateCirAreasVector() {

	for (int i = 0; i < FigCount; i++) {
		CCircle* P = dynamic_cast<CCircle*> (FigList[i]);
		if (P != NULL)
			CirAreas.push_back(FigList[i]->GetArea());
	}

	sort(CirAreas.begin(), CirAreas.end());

}

void ApplicationManager::CreateLinAreasVector() {

	for (int i = 0; i < FigCount; i++) {
		CLine* P = dynamic_cast<CLine*> (FigList[i]);
		if (P != NULL)
			LinAreas.push_back(FigList[i]->GetArea());
	}

	sort(LinAreas.begin(), LinAreas.end());

}

int ApplicationManager::GetNextRecArea(int p) {
	return RecAreas[p];
}

int ApplicationManager::GetNextCirArea(int p) {
	return CirAreas[p];
}

int ApplicationManager::GetNextTriArea(int p) {
	return TriAreas[p];
}

int ApplicationManager::GetNextLinArea(int p) {
	return LinAreas[p];
}


void ApplicationManager::ResetFigAreas(){
	RecAreas.clear();
	CirAreas.clear();
	TriAreas.clear();
	LinAreas.clear();

}



//////////////********** GILANY'S PART ************//////////////////


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();
	for (int i = 0; i < FigCount; i++)
		if (!FigList[i]->IsHidden()) {
			FigList[i]->Draw(pOut);//Call Draw function (virtual member fn)
		}

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
//Saves graph colors to the start of the textfile
void ApplicationManager::SaveGraphColors(ofstream& outfile) {
	if (outfile.is_open()) {
		outfile << pOut->getColorName(pOut->getCrntDrawColor()) << " " << pOut->getColorName(pOut->getCrntFillColor()) << " " << pOut->getColorName(UI.BkGrndColor) << "\n";
	}
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
void ApplicationManager::Deleting() {


	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{

			for (int j = i; j < FigCount; j++)
			{
				if (j < FigCount)
					FigList[j] = FigList[j + 1];
				else
				{
					delete FigList[j];
					FigList[j] = NULL;

				}

			}
			i--;
			FigCount--;
		}
	}
	pOut->ClearDrawArea();
	pOut->PrintMessage("Remaining figures: " + to_string(FigCount));

}

void ApplicationManager::DeleteAllFigs()
{
	for (int i = 0; i < MaxFigCount; i++) {
		delete FigList[i];
		FigList[i] = NULL;

	}
	FigCount = 0;
}

int ApplicationManager::SelectedNumber() {
	c = 1;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{

			c = c + 1;
		}
	}
	return c;
}

int ApplicationManager::GetFigCount()
{
	return FigCount;
}

void ApplicationManager::UnhideAllFigs()
{
	if (!isGraphEmpty()) {
		for (int i = 0; i < FigCount; i++) {
			FigList[i]->SetHidden(FALSE);
		}
	}
}
