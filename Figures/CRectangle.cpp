#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo, int figtype) :CFigure(FigureGfxInfo, figtype)
{
	Corner1 = P1;
	Corner2 = P2;
}


void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}void CRectangle::Save(std::ofstream& outfile, Output* pOut) {
	//RECTANGLE  int(ID)  int(CORNER1.x)  int(CORNER1.x)  int(CORNER2.x)  int(CORNER2.y)  string(DrawClr)  string(FillClr)
	if (outfile.is_open()) {
		outfile << "RECTANGLE ";
		outfile << ID;
		outfile << " ";

		outfile << Corner1.x << " ";
		outfile << Corner1.y << " ";
		outfile << Corner2.x << " ";
		outfile << Corner2.y << " ";

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

void CRectangle::Load(ifstream& Infile, Output* pOut, stringstream& line)
{	//Check file is open
	//Load from stringstream the object data
	if (Infile.is_open()) {
		string FIG;
		string DrawClr;
		string FillClr;
		while (line >> FIG >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> DrawClr >> FillClr) {
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
bool CRectangle::Fig(int x, int y)
{
	if ((x >= min(Corner1.x, Corner2.x) && x <= max(Corner1.x, Corner2.x) && y >= min(Corner1.y, Corner2.y) && y <= max(Corner1.y, Corner2.y)))
	{
		return true;
	}
	return false;
}
string CRectangle::PrintInfo(Output* pOut)
{
	string id = to_string(ID);
	string x1 = to_string(Corner1.x);
	string y1 = to_string(Corner1.y);
	string x2 = to_string(Corner2.x);
	string y2 = to_string(Corner2.y);

	return ("Rectangle - ID:" + id + " Corner1: (" + x1 + ", " + y1 + ")" + " Corner2: (" + x2 + ", " + y2 + ")");
}



//////////////********** GILANY'S PART ************//////////////////


Point CRectangle::GetRecHighPoint() {

	int highest = 1000;
	Point highestPoint;

	if (Corner1.y < highest) {
		highestPoint = Corner1;
		highest = Corner1.y;
	}

	if (Corner2.y < highest) {
		highestPoint = Corner2;
		highest = Corner2.y;
	}

	return highestPoint;
}

void CRectangle::ChangeCorners(Point newPoint, Point MainRefrence) {
	if (Corner1.x > MainRefrence.x)
		Corner1.x = newPoint.x + abs(MainRefrence.x - Corner1.x);
	else
		Corner1.x = newPoint.x - abs(MainRefrence.x - Corner1.x);

	if (Corner1.y > MainRefrence.y)
		Corner1.y = newPoint.y + abs(MainRefrence.y - Corner1.y);
	else
		Corner1.y = newPoint.y - abs(MainRefrence.y - Corner1.y);


	if (Corner2.x > MainRefrence.x)
		Corner2.x = newPoint.x + abs(MainRefrence.x - Corner2.x);
	else
		Corner2.x = newPoint.x - abs(MainRefrence.x - Corner2.x);

	if (Corner2.y > MainRefrence.y)
		Corner2.y = newPoint.y + abs(MainRefrence.y - Corner2.y);
	else
		Corner2.y = newPoint.y - abs(MainRefrence.y - Corner2.y);

}


int CRectangle::GetArea() {
	return (abs(Corner1.x - Corner2.x) * abs(Corner1.y - Corner2.y));
 }

Point CRectangle::GetCorner1() {
	return Corner1;
}

Point CRectangle::GetCorner2() {
	return Corner2;
}

void CRectangle::RotateFigure() {

}
//////////////********** GILANY'S PART ************//////////////////