#include "Input.h"
#include "Output.h"


Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

bool Input::DrawArea_ValidClick(int& x, int& y, int wHeight) const {
	if (y > UI.ToolBarHeight+UI.PenWidth && y < (wHeight - UI.StatusBarHeight)) {
		return true;
	}
	else {
		return false;
	}
}

string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if(Key == 8 )	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label+= Key;
		pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
				case ITM_RECT:				return DRAW_RECT;
				case ITM_CIRC:				return DRAW_CIRC;
				case ITM_LINE:				return DRAW_LINE;
				case ITM_TRIANGLE:			return DRAW_TRI;
				case ITM_ACT_UNDO:			return UNDO;
				case ITM_ACT_REDO:			return REDO;
				case ITM_SEND_TO_BACK:		return SEND_BACK;
				case ITM_BRING_TO_FRONT:	return BRNG_FRNT;
				case ITM_ROTATE_FIGURE:		return ROTATE;

				//TODO: Add more items names here
				case ITM_CHANGE_COLOR:		return CHNG_DRAW_CLR;
				case ITM_SELECT_FIGURE:		return SELECT_FIGURE;
				case ITM_RESIZE_FIGURE:		return RESIZE;
				case ITM_ZOOM_IN:			return ZOOM_IN;
				case ITM_ZOOM_OUT:			return ZOOM_OUT;
				case ITM_DELETE_FIGURE:		return DEL;
				case ITM_MOVE_FIGURE:		return MOVE;
				case ITM_COPY_FIGURE:		return COPY;
				case ITM_CUT_FIGURE:		return CUT;
				case ITM_PASTE_FIGURE:		return PASTE;
				case ITM_SAVE_GRAPH:		return SAVE;
				case ITM_LOAD_GRAPH:		return LOAD;
				case ITM_SWITCH_TO_PLAY:	return TO_PLAY;
				case ITM_EXITD:				return EXIT;
				
				default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		//[1]
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.MenuItemWidth);

			switch (ClickedItemOrder)
			{
			case ITM_GAME_TYPE:		  return Figure_Type;
			case ITM_GAME_FILL_COLOR: return Figure_Fill_Color;
			case ITM_GAME_FILL_TYPE:  return Figure_Fill_Type;
			case ITM_GAME_AREA:		  return Figure_Area;
			case ITM_SWITCH_TO_DRAW:  return TO_DRAW;
			case ITM_EXITP:			  return EXIT;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return GAMING_AREA;
		}
		//[3] User clicks on the status bar
		return STATUS;
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		return TO_PLAY;	//just for now. This should be updated
	}	

}
/////////////////////////////////
	
Input::~Input()
{
}
