#ifndef INPUT_H
#define INPUT_H

#include "..\DEFS.h"
#include "UI_Info.h" 
#include "..\CMUgraphicsLib\CMUgraphics.h"

class Output;
class Input		//The application manager should have a pointer to this class
{
private:
	window *pWind;	//Pointer to the Graphics Window
public:
	Input(window *pW);		//Consturctor
	void GetPointClicked(int &x, int &y) const;//Get coordinate where user clicks
	bool DrawArea_ValidClick(int& x, int& y, int wHeight) const;//Check if point click is in draw area
	string GetSrting(Output* pO) const ;	 //Returns a string entered by the user

	ActionType GetUserAction() const; //Read the user click and map to an action

	~Input();
};

#endif