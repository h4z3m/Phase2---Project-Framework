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
bool CLine::Fig(int x, int y)
{

	if ((x >= min(Point1.x, Point2.x) && x <= max(Point1.x, Point2.x) && y >= min(Point1.y, Point2.y) && y <= max(Point1.y, Point2.y)))
	{
		return true;
	}
	return false;
}


string CLine::PrintInfo(Output* pOut)
{
	string id = to_string(ID);
	string x1 = to_string(Point1.x);
	string y1 = to_string(Point1.y);
	string x2 = to_string(Point2.x);
	string y2 = to_string(Point2.y);


	return ("Line ID:" + id + " Point1: (" + x1 + ", " + y1 + ")" + " Point2: (" + x2 + ", " + y2 + ")");

}