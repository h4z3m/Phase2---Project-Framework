#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include <vector>


//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount,c;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	int rID=0;
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
	GfxInfo SelectInfo;

	//////////////********** GILANY'S PART ************//////////////////
	vector <CFigure*> FigVector;
	int MoveLoopCount;
	//////////////********** GILANY'S PART ************//////////////////


public:	
	ApplicationManager();
	bool isGraphEmpty();

	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	void SaveAll(ofstream&);
	void SaveGraphColors(ofstream&);
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	int GetLineCount();
	int GetCirCount();
	int GetTriCount();
	int GetRectCount();
	int GetColorFillCount(color);

	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window
	void Deleting();
	void DeleteAllFigs();
	int SelectedNumber();
	int GetFigCount();
	void UnhideAllFigs();
	//////////////********** GILANY'S PART ************//////////////////
	void MakeItSelected(CFigure*);
	void MakeItUnSelected(CFigure*);
	Point MakeRefrencePoint();
	vector <CFigure*> GetFigVector();
	CFigure* MoveLoop();
	int GetVectorSize();
	void ResetCount();
	//////////////********** GILANY'S PART ************//////////////////

};

#endif