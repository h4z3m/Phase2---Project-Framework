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
	//////////////********** Ali'S PART ************//////////////////
	virtual void resize(float);
	void Rotate(int rotation);
	virtual void zooming(float);
	Point GetMid();
	CFigure* Copy();
	void Paste(Point p, Point Mid);
	//////////////********** Ali'S PART ************//////////////////
	//////////////********** GILANY'S PART ************//////////////////
	//void ChangeRecCorners(Point, Point);
	Point GetRecHighPoint();
	virtual void ChangeCorners(Point, Point);
	virtual int GetArea();
	Point GetCorner1();
	Point GetCorner2();
	//////////////********** GILANY'S PART ************//////////////////
};

#endif