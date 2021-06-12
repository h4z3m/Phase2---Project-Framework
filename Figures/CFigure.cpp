#include "CFigure.h"
CFigure::CFigure(GfxInfo FigureGfxInfo, int figtype) : FigType(figtype)
{
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	FigGfxInfo.isHidden = false;
	Selected = false;
}
void CFigure::SetID(int rID) {
	ID = rID;
}
void CFigure::SetSelected(bool s)
{
	Selected = s;
}

bool CFigure::IsSelected() const
{
	return Selected;
}

bool CFigure::IsFilled() const
{
	if (FigGfxInfo.isFilled) {
		return true;
	}
	return false;
}

bool CFigure::IsHidden() const
{
	return FigGfxInfo.isHidden;
}

string CFigure::GetFigName()
{
	switch (FigType) {
	case line:
		return "line";
		break;

	case circle:
		return "circle";
		break;

	case rectangle:
		return "rectangle";
		break;

	case triangle:
		return "triangle";
		break;
	default:
		return "NULL";
		break;
	}
	return  "NULL";
}

color CFigure::GetFillColorObj() const
{
	return FigGfxInfo.FillClr;
}

void CFigure::ChngDrawClr(color Dclr)
{
	FigGfxInfo.DrawClr = Dclr;
}

void CFigure::ChngFillClr(color Fclr)
{
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr;
}

void CFigure::SetHidden(bool val)
{

	FigGfxInfo.isHidden = val;
}



