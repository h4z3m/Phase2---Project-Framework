#ifndef CLINE_H
#define CLINE_H

#include "CFigure.h"

class CLine : public CFigure
{
private:
	Point Point1;
	Point Point2;
public:
	CLine(Point, Point, GfxInfo FigureGfxInfo,int);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream&, Output* pOut);
	void Load(ifstream& Infile, Output* pOut, stringstream&);
	virtual string PrintInfo(Output* pOut);
	virtual bool Fig(int, int);

	//////////////********** GILANY'S PART ************//////////////////
	//void ChangeLinPoints(Point, Point);
	Point GetLinHighPoint();
	virtual void ChangeCorners(Point, Point);
	virtual int GetArea();
	virtual void RotateFigure();

	//////////////********** GILANY'S PART ************//////////////////
};

#endif