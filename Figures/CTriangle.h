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
	CTriangle(Point, Point,Point, GfxInfo FigureGfxInfo,int);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream&, Output* pOut);
	void Load(ifstream& Infile, Output* pOut, stringstream&);
	virtual bool Fig(int, int);
	virtual string PrintInfo(Output* pOut);
	//////////////********** Ali'S PART ************//////////////////
	virtual void resize(float);
	//////////////********** Ali'S PART ************//////////////////
	//////////////********** GILANY'S PART ************//////////////////
	//void ChangeTriPoints(Point, Point);
	Point GetTriHighPoint();
	virtual void ChangeCorners(Point, Point);
	virtual int GetArea();

	//////////////********** GILANY'S PART ************//////////////////
};

#endif