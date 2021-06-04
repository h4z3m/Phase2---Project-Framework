#include "CLine.h"

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo) {
	Point1 = P1;
	Point2 = P2;
}

void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawLine to draw a line on the screen	
	pOut->DrawLin(Point1, Point2, FigGfxInfo, Selected);
}void CLine::Save(std::ofstream& outfile, Output* pOut) {
	//LINE  int(ID)  int(point1.x)  int(point1.y)  int(point2.x)  int(point2.y)  DrawClr  FillClr
	if (outfile.is_open()) {
		outfile << "LINE ";
		outfile << ID << " ";

		outfile << Point1.x << " ";
		outfile << Point2.y << " ";

		//TODO: figure out how to get figure draw and fill colors as strings
		outfile << pOut->getColorName(FigGfxInfo.DrawClr) << " ";
		outfile << pOut->getColorName(FigGfxInfo.FillClr);
		outfile << "\n";
	}
}

void CLine::Load(ifstream& Infile, Output* pOut, stringstream& line)
{
	if (Infile.is_open()) {
		string FIG;
		string DrawClr;
		string FillClr;

		while (line >> FIG >> ID >> Point1.x >> Point1.y >>Point2.x>>Point2.y>>DrawClr>>FillClr) {
			if (FIG == "LINE") {
				FigGfxInfo.DrawClr = pOut->getColorObj(DrawClr);

				
			}

		}
	}
}
