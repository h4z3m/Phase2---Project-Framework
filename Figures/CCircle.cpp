#include "CCircle.h"

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	R1= P1;
	R2 = P2;
}


void CCircle ::Draw(Output* pOut) const
{
	//Call Output::DrawCir to draw a circle on the screen	
	pOut->DrawCir(R1, R2,FigGfxInfo, Selected);
}