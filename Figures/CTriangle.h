#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Point1;
	Point Point2;
	Point Point3;
public:
	CTriangle(Point, Point,Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream&, Output* pOut);
	void Load(ifstream& Infile, Output* pOut, stringstream&);
	virtual bool Fig(int, int);
	virtual string PrintInfo(Output* pOut);

	//////////////********** GILANY'S PART ************//////////////////
	void ChangeTriPoints(Point, Point);
	Point GetTriHighPoint();
	//////////////********** GILANY'S PART ************//////////////////
};

#endif