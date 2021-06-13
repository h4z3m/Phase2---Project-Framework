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
//void CRectangle::ChangeRecCorners(Point newPoint, Point MainRefrence) {
//	if (Corner1.x > MainRefrence.x)
//		Corner1.x = newPoint.x + abs(MainRefrence.x - Corner1.x);
//	else
//		Corner1.x = newPoint.x - abs(MainRefrence.x - Corner1.x);
//
//	if (Corner1.y > MainRefrence.y)
//		Corner1.y = newPoint.y + abs(MainRefrence.y - Corner1.y);
//	else
//		Corner1.y = newPoint.y - abs(MainRefrence.y - Corner1.y);
//
//
//	if (Corner2.x > MainRefrence.x)
//		Corner2.x = newPoint.x + abs(MainRefrence.x - Corner2.x);
//	else
//		Corner2.x = newPoint.x - abs(MainRefrence.x - Corner2.x);
//
//	if (Corner2.y > MainRefrence.y)
//		Corner2.y = newPoint.y + abs(MainRefrence.y - Corner2.y);
//	else
//		Corner2.y = newPoint.y - abs(MainRefrence.y - Corner2.y);
//}

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
//////////////********** GILANY'S PART ************//////////////////
//////////////********** Ali'S PART ************//////////////////
void CRectangle::resize(float factor)
{
	int side_x = Corner2.x - Corner1.x;
	int side_y = Corner2.y - Corner1.y;
	Corner2.x = Corner1.x + (side_x * factor);
	Corner2.y = Corner1.y + (side_y * factor);

}
//////////////********** Ali'S PART ************//////////////////
void CRectangle::Rotate(int rotation) {
	//Temp pts
	Point P1 = Corner1;
	Point P2 = Corner2;
	//1->180, 0=90,2=270
	//Rotate 180 degrees counter clockwise
	if (rotation == 1) {
		int side_x = Corner2.x - Corner1.x;
		int side_y = Corner2.y - Corner1.y;
		Corner2.x = Corner1.x + (side_x);
		Corner2.y = Corner1.y - (side_y);
	}
	//Rotate 90/270 degrees counter clockwise
	else {
		for (int i = 0; i < rotation + 1; i++) {
			//Temp pts
			Point P1 = Corner1;
			Point P2 = Corner2;
			int side_x = Corner2.x - Corner1.x;
			int side_y = Corner2.y - Corner1.y;
			Corner2.x = P1.x - side_y;
			Corner2.y = P1.y + side_x;
		}
	}
}

void CRectangle::zooming(float factor)
{
	int centerx = UI.width / 2;
	int centery = UI.height / 2;

	float point1x = Corner1.x - centerx;
	float point1y = Corner1.y - centery;
	float length1 = sqrt(pow(point1x, 2) + pow(point1y, 2));

	float point2x = Corner2.x - centerx;
	float point2y = Corner2.y - centery;
	float length2 = sqrt(pow(point2x, 2) + pow(point2y, 2));

	length1 = length1 * factor;
	length2 = length2 * factor;

	float anglepoint1 = atan(abs(point1y) / abs(point1x));
	float anglepoint2 = atan(abs(point2y) / abs(point2x));

	if (point1x > 0) {
		Corner1.x = centerx + cos(anglepoint1) * length1;
	}
	else {
		Corner1.x = centerx - cos(anglepoint1) * length1;
	}

	if (point1y > 0) {
		Corner1.y = centery + sin(anglepoint1) * length1;
	}
	else {
		Corner1.y = centery - sin(anglepoint1) * length1;
	}

	if (point2x > 0) {
		Corner2.x = centerx + cos(anglepoint2) * length2;
	}
	else {
		Corner2.x = centerx - cos(anglepoint2) * length2;
	}

	if (point2y > 0) {
		Corner2.y = centery + sin(anglepoint2) * length2;
	}
	else {
		Corner2.y = centery - sin(anglepoint2) * length2;
	}


}
Point CRectangle::GetMid()
{
	Point Mid;
	Mid.x = abs(Corner1.x - Corner2.x) / 2;
	Mid.y = abs(Corner1.y - Corner2.y) / 2;
	return Mid;
}
CFigure* CRectangle::Copy() {
	CRectangle* R = new CRectangle(*this);
	R->SetSelected(false);
	return R;
}

void CRectangle::Paste(Point p, Point Mid) {
	Corner1.x = p.x - (Mid.x - Corner1.x);
	Corner1.y = p.y - (Mid.y - Corner1.y);
	Corner2.x = p.x - (Mid.x - Corner2.x);
	Corner2.y = p.y - (Mid.y - Corner2.y);
}