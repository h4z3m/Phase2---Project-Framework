#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo,int figtype) :CFigure(FigureGfxInfo, figtype) {
	Point1 = P1;
	Point2 = P2;
	Point3 = P3;
}

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTri to draw a line on the screen	
	pOut->DrawTri(Point1, Point2, Point3, FigGfxInfo, Selected);

}void CTriangle::Save(std::ofstream& outfile, Output* pOut) {
	//TRIANGLE  int(ID)  int(point1.x)  int(point1.y)  int(point2.x)  int(point2.y)  int(point3.x)  int(point3.y)  string(DrawClr)  string(FillClr)
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
float area(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

bool CTriangle::Fig(int x, int y)              //Function to inform me if the point in the figure or not
{
	float A = area(Point1.x, Point1.y, Point2.x, Point2.y, Point3.x, Point3.y);
	float A1 = area(x, y, Point2.x, Point2.y, Point3.x, Point3.y);
	float A2 = area(Point1.x, Point1.y, x, y, Point3.x, Point3.y);
	float A3 = area(Point1.x, Point1.y, Point2.x, Point2.y, x, y);
	if (A == A1 + A2 + A3)
	{
		return true;
	}
	return false;
}

string CTriangle::PrintInfo(Output* pOut)
{
	string id = to_string(ID);
	string x1 = to_string(Point1.x);
	string y1 = to_string(Point1.y);
	string x2 = to_string(Point2.x);
	string y2 = to_string(Point2.y);
	string x3 = to_string(Point3.x);
	string y3 = to_string(Point3.y);



	return ("Triangle - ID:" + id + " Corner1: (" + x1 + ", " + y1 + ")" + " Corner2: (" + x2 + ", " + y2 + ")" + " Corner3: (" + x3 + ", " + y3 + ")");

}

//////////////********** GILANY'S PART ************//////////////////
//void CTriangle::ChangeTriPoints(Point newPoint, Point MainRefrence) {
//
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
//
//
//
//	if (Point3.x > MainRefrence.x)
//		Point3.x = newPoint.x + abs(MainRefrence.x - Point3.x);
//	else
//		Point3.x = newPoint.x - abs(MainRefrence.x - Point3.x);
//
//	if (Point3.y > MainRefrence.y)
//		Point3.y = newPoint.y + abs(MainRefrence.y - Point3.y);
//	else
//		Point3.y = newPoint.y - abs(MainRefrence.y - Point3.y);
//}

Point CTriangle::GetTriHighPoint() {

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

	if (Point3.y < highest) {
		highestPoint = Point3;
		highest = Point3.y;
	}

	return highestPoint;
}

void CTriangle::ChangeCorners(Point newPoint, Point MainRefrence) {
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



	if (Point3.x > MainRefrence.x)
		Point3.x = newPoint.x + abs(MainRefrence.x - Point3.x);
	else
		Point3.x = newPoint.x - abs(MainRefrence.x - Point3.x);

	if (Point3.y > MainRefrence.y)
		Point3.y = newPoint.y + abs(MainRefrence.y - Point3.y);
	else
		Point3.y = newPoint.y - abs(MainRefrence.y - Point3.y);
}

int CTriangle::GetArea() {
	return (12 * abs(Point1.x * (Point2.y - Point3.y) + Point2.x * (Point3.y - Point1.y) + Point3.x * (Point1.y - Point2.y)));
}
//////////////********** GILANY'S PART ************//////////////////
//////////////********** Ali'S PART ************//////////////////
void CTriangle::resize(float factor)
{
	float side1_x = Point2.x - Point1.x;
	float side1_y = Point2.y - Point1.y;
	float length1 = sqrt(pow(side1_x, 2) + pow(side1_y, 2));

	float side2_x = Point3.x - Point1.x;
	float side2_y = Point3.y - Point1.y;
	float length2 = sqrt(pow(side2_x, 2) + pow(side2_y, 2));

	length1 = length1 * factor;
	length2 = length2 * factor;

	float angle1 = atan(side1_y / side1_x);
	Point2.x = Point1.x + cos(angle1) * length1;
	Point2.y = Point1.y + sin(angle1) * length1;

	float angle2 = atan(side2_y / side2_x);
	Point3.x = Point1.x + cos(angle2) * length2;
	Point3.y = Point1.y + sin(angle2) * length2;



}
//////////////********** Ali'S PART ************//////////////////
void CTriangle::Rotate(int rotation) {
	
	for (int i = 0; i < rotation + 1; i++) {
		Point Center;
		Center.x = (Point1.x + Point2.x + Point3.x) / 3;
		Center.y = (Point1.y + Point2.y + Point3.y) / 3;


		Point NewPoint1;
		NewPoint1.x = Center.x - (Point1.y - Center.y);
		NewPoint1.y = Center.y + (Point1.x - Center.x);
		Point NewPoint2;
		NewPoint2.x = Center.x - (Point2.y - Center.y);
		NewPoint2.y = Center.y + (Point2.x - Center.x);
		Point NewPoint3;
		NewPoint3.x = Center.x - (Point3.y - Center.y);
		NewPoint3.y = Center.y + (Point3.x - Center.x);

		Point1 = NewPoint1;
		Point2 = NewPoint2;
		Point3 = NewPoint3;
	
	}
}
void CTriangle::zooming(float factor)
{
	int centerx = UI.width/2;
	int centery = UI.height/2;

	float point1x = Point1.x - centerx;
	float point1y = Point1.y - centery;
	float length1 = sqrt(pow(point1x, 2) + pow(point1y, 2));

	float point2x = Point2.x - centerx;
	float point2y = Point2.y - centery;
	float length2 = sqrt(pow(point2x, 2) + pow(point2y, 2));

	float point3x = Point3.x - centerx;
	float point3y = Point3.y - centery;
	float length3 = sqrt(pow(point3x, 2) + pow(point3y, 2));

	length1 = length1 * factor;
	length2 = length2 * factor;
	length3 = length3 * factor;

	float anglepoint1 = atan(abs(point1y) / abs(point1x));
	float anglepoint2 = atan(abs(point2y) / abs(point2x));
	float anglepoint3 = atan(abs(point3y) / abs(point3x));


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

	if (point3x > 0) {
		Point3.x = centerx + cos(anglepoint3) * length3;
	}
	else {
		Point3.x = centerx - cos(anglepoint3) * length3;
	}

	if (point3y > 0) {
		Point3.y = centery + sin(anglepoint3) * length3;
	}
	else {
		Point3.y = centery - sin(anglepoint3) * length3;
	}


}

Point CTriangle::GetMid()
{
	Point Mid;
	Mid.x = (Point1.x + Point2.x + Point3.x) / 3;
	Mid.y = (Point1.y + Point2.y + Point3.y) / 3;
	return Mid;
}
CFigure* CTriangle::Copy() {
	CTriangle* T = new CTriangle(*this);
	T->SetSelected(false);
	return T;
}

void CTriangle::Paste(Point p, Point Mid) {
	Point1.x = p.x - (Mid.x - Point1.x);
	Point1.y = p.y - (Mid.y - Point1.y);
	Point2.x = p.x - (Mid.x - Point2.x);
	Point2.y = p.y - (Mid.y - Point2.y);
	Point3.x = p.x - (Mid.x - Point3.x);
	Point3.y = p.y - (Mid.y - Point3.y);

}