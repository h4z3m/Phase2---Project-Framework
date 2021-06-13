#include "CCircle.h"
CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo,int figtype) :CFigure(FigureGfxInfo,figtype)
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
	//CIRCLE  int(ID)  int(R1.x)  int(R1.y)  int(R2.x)  int(R2.y)  float(radius)  string(DrawClr)  string(FillClr)
	if (outfile.is_open()) {
		outfile << "CIRCLE ";
		outfile << ID << " ";

		outfile << R1.x << " ";
		outfile << R1.y << " ";

		outfile << R2.x << " ";
		outfile << R2.y << " ";

		outfile << sqrt(pow(R2.x - R1.x, 2) + pow(R2.y - R1.y, 2) * 1.0) << " ";

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

void CCircle::Load(ifstream& Infile, Output* pOut, stringstream& line)
{	//Check file is open
	//Load from stringstream the object data
	if (Infile.is_open()) {
		string FIG;
		string DrawClr;
		string FillClr;
		float rRadius;
		while (line >> FIG >> ID >> R1.x >> R1.y >> R2.x >> R2.y >> rRadius >> DrawClr >> FillClr) {
			if (FIG == "CIRCLE") {
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
}
string CCircle::PrintInfo(Output* pOut)
{

	string id = to_string(ID);
	string x = to_string(R1.x);
	string y = to_string(R1.y);



	return ("Circle ID: " + id + " Center: (" + x + ", " + y + ")");

}

bool CCircle::Fig(int x, int y)  //Determine the position of the point
{
	radius = (sqrt(pow(R2.x - R1.x, 2) + pow(R2.y - R1.y, 2) * 1.0));
	double Center2Click= (sqrt(pow(x - R1.x, 2) + pow(y - R1.y, 2) * 1.0));
	if (Center2Click <= radius) {
		return true;
	}
	return false;
}

//////////////********** GILANY'S PART ************//////////////////
//void CCircle::ChangeCirPoints(Point P1) {
//	radius = (sqrt(pow(R2.x - R1.x, 2) + pow(R2.y - R1.y, 2) * 1.0));
//	//Using the midpoint of a parallelogram joining the 4 points of old and new circle
//	R2.x = P1.x + R2.x - R1.x;
//	R2.y = P1.y + R2.y - R1.y;
//	R1 = P1;
//
//
//}

Point CCircle::GetCirHighPoint() {
	return R1;
}


void CCircle::ChangeCorners(Point newPoint, Point MainRefrence) {

	if (R1.x > MainRefrence.x)
		R1.x = newPoint.x + abs(MainRefrence.x - R1.x);
	else
		R1.x = newPoint.x - abs(MainRefrence.x - R1.x);

	if (R1.y > MainRefrence.y)
		R1.y = newPoint.y + abs(MainRefrence.y - R1.y);
	else
		R1.y = newPoint.y - abs(MainRefrence.y - R1.y);


	if (R2.x > MainRefrence.x)
		R2.x = newPoint.x + abs(MainRefrence.x - R2.x);
	else
		R2.x = newPoint.x - abs(MainRefrence.x - R2.x);

	if (R2.y > MainRefrence.y)
		R2.y = newPoint.y + abs(MainRefrence.y - R2.y);
	else
		R2.y = newPoint.y - abs(MainRefrence.y - R2.y);


}

int CCircle::GetArea() {
	radius = (sqrt(pow(R2.x - R1.x, 2) + pow(R2.y - R1.y, 2) * 1.0));
	return (3.141592654 * pow(radius, 2));
}

void CCircle::Rotate(int)
{
}

//////////////********** GILANY'S PART ************//////////////////
void CCircle::resize(float factor)
{
	float move_in_x = R2.x - R1.x;
	float move_in_y = R2.y - R1.y;
	float radius = sqrt(pow(move_in_x, 2) + pow(move_in_y, 2));
	radius = radius * factor;
	float angle = atan(move_in_y / move_in_x);
	R2.x = R1.x + cos(angle) * radius;
	R2.y = R1.y + sin(angle) * radius;
}
void CCircle::zooming(float factor)
{
	int centerx = UI.width / 2;
	int centery = UI.height / 2;

	float point1x = R1.x - centerx;
	float point1y = R1.y - centery;
	float length1 = sqrt(pow(point1x, 2) + pow(point1y, 2));

	float point2x = R2.x - centerx;
	float point2y = R2.y - centery;
	float length2 = sqrt(pow(point2x, 2) + pow(point2y, 2));

	length1 = length1 * factor;
	length2 = length2 * factor;

	float anglepoint1 = atan(abs(point1y) / abs(point1x));
	float anglepoint2 = atan(abs(point2y) / abs(point2x));

	if (point1x > 0) {
		R1.x = centerx + cos(anglepoint1) * length1;
	}
	else {
		R1.x = centerx - cos(anglepoint1) * length1;
	}

	if (point1y > 0) {
		R1.y = centery + sin(anglepoint1) * length1;
	}
	else {
		R1.y = centery - sin(anglepoint1) * length1;
	}

	if (point2x > 0) {
		R2.x = centerx + cos(anglepoint2) * length2;
	}
	else {
		R2.x = centerx - cos(anglepoint2) * length2;
	}

	if (point2y > 0) {
		R2.y = centery + sin(anglepoint2) * length2;
	}
	else {
		R2.y = centery - sin(anglepoint2) * length2;
	}


}
Point CCircle::GetMid()
{
	Point Mid;
	Mid = R1;
	return Mid;
}
CFigure* CCircle::Copy()
{
	CCircle* C = new CCircle(*this);
	C->SetSelected(false);
	return C;
}
void CCircle::Paste(Point p, Point Mid) {
	R1.x = p.x - (Mid.x - R1.x);
	R1.y = p.y - (Mid.y - R1.y);
	R2.x = p.x - (Mid.x - R2.x);
	R2.y = p.y - (Mid.y - R2.y);
}