#ifndef CCIRCLE_H
#define CCIRCLE_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point R1;
	Point R2;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	void Save(ofstream&, Output* pOut);
	void Load(ifstream& Infile,Output* pOut,stringstream&);
	virtual bool Fig(int, int);
	virtual string PrintInfo(Output* pOut);
};

#endif