#ifndef CFIGURE_H
#define CFIGURE_H
#include <fstream>
#include <istream>
#include <sstream>
#include <string>
#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	int ID = rand();		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	/// Add more parameters if needed.

public:
	const int FigType;
	CFigure(GfxInfo FigureGfxInfo, int FigType);
	void SetID(int rID);
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	bool IsFilled() const;		//check if figure is filled
	bool IsHidden() const;
	string GetFigName();
	color GetFillColorObj() const;	//gets color of a figure
	color GetDrawColorObj() const;
	virtual void Draw(Output* pOut) const = 0;		//Draw the figure
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	void SetHidden(bool);
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	



	virtual void Save(ofstream& OutFile, Output* pOut) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream& Infile, Output* pOut, stringstream&) = 0;	//Load the figure parameters to the file
	virtual string PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
	virtual bool Fig(int, int) = 0;
	//////////////********** Ali'S PART ************//////////////////
	virtual void resize(float) = 0;
	virtual void zooming(float) = 0;
	//////////////********** Ali'S PART ************//////////////////

	virtual void ChangeCorners(Point, Point) = 0;
	virtual int GetArea() = 0;
	virtual void Rotate(int) = 0;

};

#endif