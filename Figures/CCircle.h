#ifndef CCIRCLE_H
#define CCIRCLE_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point R1;
	Point R2;
	double radius;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo,int);
	virtual void Draw(Output* pOut) const;
	void Save(ofstream&, Output* pOut);
	void Load(ifstream& Infile,Output* pOut,stringstream&);
	virtual bool Fig(int, int);
	virtual string PrintInfo(Output* pOut);

	//////////////********** Ali'S PART ************//////////////////
	virtual void resize(float);
	virtual void zooming(float);
	Point GetMid();
	CFigure* Copy();
	void Paste(Point p, Point Mid);
	//////////////********** Ali'S PART ************//////////////////
	//////////////********** GILANY'S PART ************//////////////////
		//void ChangeCirPoints(Point);
	Point GetCirHighPoint();
	virtual void ChangeCorners(Point, Point);
	virtual int GetArea();
	virtual void Rotate(int);
	//////////////********** GILANY'S PART ************//////////////////
};

#endif