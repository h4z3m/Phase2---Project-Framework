#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo) {
	Point1 = P1;
	Point2 = P2;
	Point3 = P3;
}

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTri to draw a line on the screen	
	pOut->DrawTri(Point1, Point2, Point3, FigGfxInfo, Selected);

}void CTriangle::Save(std::ofstream& outfile, Output* pOut) {
	//TRIANGLE  int(ID)  int(point1.x)  int(point1.y)  int(point2.x)  int(point2.y)  int(point3.x)  int(point3.y)  DrawClr  FillClr
	if (outfile.is_open()) {
		outfile << "TRIANGLE ";
		outfile << ID;
		outfile << " ";

		outfile << Point1.x << " ";
		outfile << Point1.y << " ";
		outfile << Point2.x << " ";
		outfile << Point2.y << " ";
		outfile << Point3.x << " ";
		outfile << Point3.y << " ";

		//TODO: figure out how to get figure draw and fill colors as strings
		outfile << pOut->getColorName(FigGfxInfo.DrawClr) << " ";
		if (FigGfxInfo.isFilled == true) {
			outfile << pOut->getColorName(FigGfxInfo.FillClr);
		}
		else {
			outfile << "NO_FILL";
		}
		outfile << "\n";
	}
}

void CTriangle::Load(ifstream& Infile, Output* pOut, stringstream& line)
{
	if (Infile.is_open()) {
		string FIG;
		string DrawClr;
		string FillClr;
		while (line >> FIG >> ID >> Point1.x >> Point1.y >> Point2.x >> Point2.y >> Point3.x >> Point3.y >> DrawClr >> FillClr) {

			FigGfxInfo.DrawClr = pOut->getColorObj(DrawClr);
			FigGfxInfo.FillClr = pOut->getColorObj(FillClr);
			if (FillClr == "NO_FILL") {
				FigGfxInfo.isFilled = false;
			}
			else {
				FigGfxInfo.isFilled = true;
			}

		}
	}
}
