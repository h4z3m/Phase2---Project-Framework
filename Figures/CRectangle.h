#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo,int);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream&, Output* pOut);
	void Load(ifstream& Infile, Output* pOut, stringstream&);
	virtual string PrintInfo(Output* pOut);
	virtual bool Fig(int, int);

	//////////////********** GILANY'S PART ************//////////////////
	void ChangeRecCorners(Point, Point);
	Point GetRecHighPoint();
	//////////////********** GILANY'S PART ************//////////////////
};

#endif