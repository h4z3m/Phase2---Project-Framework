#include "CLine.h"
#include "CTriangle.h"

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo, int figtype) :CFigure(FigureGfxInfo, figtype) {
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

		while (line >> FIG >> ID >> Point1.x >> Point1.y >> Point2.x >> Point2.y >> DrawClr) {
			if (FIG == "LINE") {
				FigGfxInfo.DrawClr = pOut->getColorObj(DrawClr);
			}

		}
	}
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

//////////////********** GILANY'S PART ************//////////////////
//void CLine::ChangeLinPoints(Point newPoint, Point MainRefrence) {
//	if (Point1.x > MainRefrence.x)
//		Point1.x = newPoint.x + abs(MainRefrence.x - Point1.x);
//	else
//		Point1.x = newPoint.x - abs(MainRefrence.x - Point1.x);
//
//	if (Point1.y > MainRefrence.y)
//		Point1.y = newPoint.y + abs(MainRefrence.y - Point1.y);
//	else
//		Point1.y = newPoint.y - abs(MainRefrence.y - Point1.y);
//
//
//	if (Point2.x > MainRefrence.x)
//		Point2.x = newPoint.x + abs(MainRefrence.x - Point2.x);
//	else
//		Point2.x = newPoint.x - abs(MainRefrence.x - Point2.x);
//
//	if (Point2.y > MainRefrence.y)
//		Point2.y = newPoint.y + abs(MainRefrence.y - Point2.y);
//	else
//		Point2.y = newPoint.y - abs(MainRefrence.y - Point2.y);
//}

Point CLine::GetLinHighPoint() {

	int highest = 1000;
	Point highestPoint;

	if (Point1.y < highest) {
		highestPoint = Point1;
		highest = Point1.y;
	}

	if (Point2.y < highest) {
		highestPoint = Point2;
		highest = Point2.y;
	}

	return highestPoint;
}

void CLine::ChangeCorners(Point newPoint, Point MainRefrence) {
	if (Point1.x > MainRefrence.x)
		Point1.x = newPoint.x + abs(MainRefrence.x - Point1.x);
	else
		Point1.x = newPoint.x - abs(MainRefrence.x - Point1.x);

	if (Point1.y > MainRefrence.y)
		Point1.y = newPoint.y + abs(MainRefrence.y - Point1.y);
	else
		Point1.y = newPoint.y - abs(MainRefrence.y - Point1.y);


	if (Point2.x > MainRefrence.x)
		Point2.x = newPoint.x + abs(MainRefrence.x - Point2.x);
	else
		Point2.x = newPoint.x - abs(MainRefrence.x - Point2.x);

	if (Point2.y > MainRefrence.y)
		Point2.y = newPoint.y + abs(MainRefrence.y - Point2.y);
	else
		Point2.y = newPoint.y - abs(MainRefrence.y - Point2.y);
}

int CLine::GetArea() {
	return  (sqrt(pow(Point1.x - Point2.x, 2) + pow(Point1.y - Point2.y, 2) * 1.0));
}

//////////////********** GILANY'S PART ************//////////////////
//////////////********** Ali'S PART ************//////////////////
double CLine::Triangle_area(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}


bool CLine::Fig(int x, int y)
{

	double area = Triangle_area(x, y, Point1.x, Point1.y, Point2.x, Point2.y);
	if (area >= 0 && area <= 1000 && (x >= min(Point1.x, Point2.x) && x <= max(Point1.x, Point2.x) && y >= min(Point1.y, Point2.y) && y <= max(Point1.y, Point2.y)))
	{
		return true;
	}
	return false;
}

void CLine::resize(float factor)
{
	float sidex = Point2.x - Point1.x;
	float sidey = Point2.y - Point1.y;
	float length = sqrt(pow(sidex, 2) + pow(sidey, 2));
	length = length * factor;
	float angle = atan(sidey / sidex);
	Point2.x = Point1.x + cos(angle) * length;
	Point2.y = Point1.y + sin(angle) * length;

}
//////////////********** Ali'S PART ************//////////////////
void CLine::Rotate(int rotation) {
	for (int i = 0; i < rotation + 1; i++) {
		//Temp pts
		Point P1 = Point1;
		Point P2 = Point2;
		int sidex = Point2.x - Point1.x;
		int sidey = Point2.y - Point1.y;

		if (sidex > 0 && sidey > 0) {
			Point2.x = P2.x - 2 * abs(sidex);
		}
		else if (sidex < 0 && sidey > 0) {
			Point2.y = P2.y - 2 * abs(sidey);
		}
		else if (sidex < 0 && sidey < 0) {
			Point2.x = P2.x + 2 * abs(sidex);
		}
		else if (sidex > 0 && sidey < 0) {
			Point2.y = P2.y + 2 * abs(sidey);
		}
	}
}
void CLine::zooming(float factor)
{
	int centerx = UI.width / 2;
	int centery = UI.height / 2;

	float point1x = Point1.x - centerx;
	float point1y = Point1.y - centery;
	float length1 = sqrt(pow(point1x, 2) + pow(point1y, 2));

	float point2x = Point2.x - centerx;
	float point2y = Point2.y - centery;
	float length2 = sqrt(pow(point2x, 2) + pow(point2y, 2));

	length1 = length1 * factor;
	length2 = length2 * factor;

	float anglepoint1 = atan(abs(point1y) / abs(point1x));
	float anglepoint2 = atan(abs(point2y) / abs(point2x));

	if (point1x > 0) {
		Point1.x = centerx + cos(anglepoint1) * length1;
	}
	else {
		Point1.x = centerx - cos(anglepoint1) * length1;
	}

	if (point1y > 0) {
		Point1.y = centery + sin(anglepoint1) * length1;
	}
	else {
		Point1.y = centery - sin(anglepoint1) * length1;
	}

	if (point2x > 0) {
		Point2.x = centerx + cos(anglepoint2) * length2;
	}
	else {
		Point2.x = centerx - cos(anglepoint2) * length2;
	}

	if (point2y > 0) {
		Point2.y = centery + sin(anglepoint2) * length2;
	}
	else {
		Point2.y = centery - sin(anglepoint2) * length2;
	}

}
Point CLine::GetMid()
{
	Point Mid;
	Mid.x = (Point1.x + Point1.x) / 2;
	Mid.y = (Point1.y + Point1.y) / 2;
	return Mid;
}
CFigure* CLine::Copy() {
	CLine* L = new CLine(*this);
	L->SetSelected(false);
	return L;
}

void CLine::Paste(Point p, Point Mid)
{
	Point1.x = p.x - (Mid.x - Point1.x);
	Point1.y = p.y - (Mid.y - Point1.y);
	Point2.x = p.x - (Mid.x - Point2.x);
	Point2.y = p.y - (Mid.y - Point2.y);
}