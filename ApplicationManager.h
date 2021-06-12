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
	CFigure* SmallestArea;
	int MoveLoopCount=0;

	vector <int> RecAreas;
	vector <int> CirAreas;
	vector <int> TriAreas;
	vector <int> LinAreas;

	int RecAreaCount;
	int TriAreaCount;
	int LinAreaCount;
	int CirAreaCount;
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
	int GetLineCountWColor(color);
	int GetCirCountWColor(color);
	int GetTriCountWColor(color);
	int GetRectCountWColor(color);
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
	//////////////********** Ali'S PART ************//////////////////
	void Changesize(float factor);
	//////////////********** Ali'S PART ************//////////////////
	//////////////********** GILANY'S PART ************//////////////////
	void MakeItSelected(CFigure*);
	void MakeItUnSelected(CFigure*);
	Point MakeRefrencePoint();
	vector <CFigure*> GetFigVector();
	CFigure* MoveLoop();
	void AreaLoop();

	int GetVectorSize();
	void ResetCount();

	bool CheckSmallest(CFigure*);

	void CreateAreasVector();
	void CreateRecAreasVector();
	void CreateTriAreasVector();
	void CreateCirAreasVector();
	void CreateLinAreasVector();


	int GetNextRecArea(int p);
	int GetNextCirArea(int p);
	int GetNextLinArea(int p);
	int GetNextTriArea(int p);

	friend bool CheckValidationPoint(Point P2);

	void ResetFigAreas();
	//////////////********** GILANY'S PART ************//////////////////
	void ReorderFigList(CFigure*[], int, int);
	
};

#endif