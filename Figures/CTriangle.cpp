#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point P3,GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo) {
	Point1 = P1;
	Point2 = P2;
	Point3 = P3;
}

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTri to draw a line on the screen	
	pOut->DrawTri(Point1, Point2, Point3,FigGfxInfo, Selected);
}