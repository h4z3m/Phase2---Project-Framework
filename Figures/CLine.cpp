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
	//LINE  int(ID)  int(point1.x)  int(point1.y)  int(point2.x)  int(point2.y)  string(DrawClr)  string(FillClr)
	if (outfile.is_open()) {
		outfile << "LINE ";
		outfile << ID << " ";

		outfile << Point1.x << " ";
		outfile << Point1.y << " ";
		outfile << Point2.x << " ";
		outfile << Point2.y << " ";

		outfile << pOut->getColorName(FigGfxInfo.DrawClr) << " ";
		outfile << "\n";
	}
}

void CLine::Load(ifstream& Infile, Output* pOut, stringstream& line)
{
	//Check file is open
	//Load from stringstream the object data
	if (Infile.is_open()) {
		string FIG;
		string DrawClr;
		string FillClr;

		while (line >> FIG >> ID >> Point1.x >> Point1.y >>Point2.x>>Point2.y>>DrawClr) {
			if (FIG == "LINE") {
				FigGfxInfo.DrawClr = pOut->getColorObj(DrawClr);				
			}

		}
	}
}
