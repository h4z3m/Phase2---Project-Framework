#include "CCircle.h"

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	R1 = P1;
	R2 = P2;
}

void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCir to draw a circle on the screen	
	pOut->DrawCir(R1, R2, FigGfxInfo, Selected);
}
void CCircle::Save(ofstream& outfile, Output* pOut) {
	//CIRCLE  int(ID)  int(x)  int(y)  float(radius)  DrawClr  FillClr
	if (outfile.is_open()) {
		outfile << "CIRCLE ";
		outfile << ID << " ";

		outfile << R1.x << " ";
		outfile << R2.y << "  ";
		outfile << sqrt(pow(R2.x - R1.x, 2) + pow(R2.y - R1.y, 2) * 1.0) << " ";

		//TODO: figure out how to get figure draw and fill colors as strings

		
		outfile << pOut->getColorName(FigGfxInfo.DrawClr) << " ";
		outfile << pOut->getColorName(FigGfxInfo.FillClr);
		outfile << "\n";
	}
}

