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
void CCircle::ChangeCirPoints(Point P1) {
	radius = (sqrt(pow(R2.x - R1.x, 2) + pow(R2.y - R1.y, 2) * 1.0));
	//Using the midpoint of a parallelogram joining the 4 points of old and new circle
	R2.x = P1.x + R2.x - R1.x;
	R2.y = P1.y + R2.y - R1.y;
	R1 = P1;


}

Point CCircle::GetCirHighPoint() {
	return R1;
}
//////////////********** GILANY'S PART ************//////////////////