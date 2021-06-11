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
	int ID=rand();		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	/// Add more parameters if needed.

public:
	int FigType;
	CFigure(GfxInfo FigureGfxInfo);
	void SetID(int rID);
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	bool IsFilled() const;		//check if figure is filled
	bool IsHidden() const;
	color GetFillColorObj() const;	//gets color of a figure
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	void SetHidden(bool);
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	//virtual void Rotate() = 0;	//Rotate the figure
	//virtual void Resize() = 0;	//Resize the figure
	//virtual void Move() = 0;		//Move the figure

	virtual void Save(ofstream &OutFile, Output* pOut) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile, Output* pOut,stringstream&) = 0;	//Load the figure parameters to the file
	virtual string PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
	virtual bool Fig(int, int) = 0;
};

#endif