#include "CLine.h"

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo) {
	Point1 = P1;
	Point2 = P2;
}

void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawLine to draw a line on the screen	
	pOut->DrawLin(Point1, Point2, FigGfxInfo, Selected);
}