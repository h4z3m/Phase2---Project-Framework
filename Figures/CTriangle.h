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
};

#endif