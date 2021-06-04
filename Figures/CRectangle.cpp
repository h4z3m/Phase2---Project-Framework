#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}


void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}void CRectangle::Save(std::ofstream& outfile, Output* pOut) {
	//RECTANGLE  int(ID)  int(CORNER1.x)  int(CORNER1.x)  int(CORNER2.x)  int(CORNER2.y)  DrawClr  FillClr
	if (outfile.is_open()) {
		outfile << "RECTANGLE ";
		outfile << ID;
		outfile << " ";

		outfile << Corner1.x << " ";
		outfile << Corner1.y << " ";
		outfile << Corner2.x << " ";
		outfile << Corner2.y << " ";
		//TODO: figure out how to get figure draw and fill colors as strings
		outfile << pOut->getColorName(FigGfxInfo.DrawClr) << " ";
		outfile << pOut->getColorName(FigGfxInfo.FillClr);
		outfile << "\n";
	}

}

void CRectangle::Load(ifstream& Infile, Output* pOut, stringstream& line)
{
	if (Infile.is_open()) {
		string FIG;
		string DrawClr;
		string FillClr;
		while (line >> FIG >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> DrawClr >> FillClr) {
			if (FIG == "RECTANGLE") {
				FigGfxInfo.DrawClr = pOut->getColorObj(DrawClr);
				FigGfxInfo.FillClr = pOut->getColorObj(FillClr);
				if (FigGfxInfo.FillClr == GRAY) {
					FigGfxInfo.isFilled = false;
				}
			}

		}
	}
}
