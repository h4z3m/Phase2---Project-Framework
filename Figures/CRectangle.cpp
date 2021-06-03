#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}


void CRectangle::GetNewCenter() {
	

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Click on new center");

	//Read center and store in point P1
	pIn->GetPointClicked(NewCenter.x, NewCenter.y);


}

Point CRectangle::CenterCalc_corner1() {
	int disC_P1_X = RecCenter.x - Corner1.x;
	int disC_P1_Y = Corner1.y - RecCenter.y;


	Point NewCorner1;

	NewCorner1.x = NewCenter.x - disC_P1_X;
	NewCorner1.y = NewCenter.y + disC_P1_Y;
	
	return NewCorner1;
}

Point CRectangle::CenterCalc_corner2() {


	int disC_P2_X = Corner2.x - RecCenter.x;
	int disC_P2_Y = RecCenter.y - Corner2.y;

	Point NewCorner2;

	NewCorner2.x = NewCenter.x + disC_P2_X;
	NewCorner2.y = NewCenter.y - disC_P2_Y;


	return NewCorner2;

}