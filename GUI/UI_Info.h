#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_RECT,		//Recangle item in menu
	ITM_CIRC,		//Circle item in menu
	ITM_LINE,
	ITM_TRIANGLE,
	ITM_ACT_UNDO,
	ITM_ACT_REDO,
	ITM_SEND_TO_BACK,
	ITM_BRING_TO_FRONT,
	ITM_ROTATE_FIGURE,
	//TODO: Add more items names here
	ITM_CHANGE_COLOR,
	ITM_SELECT_FIGURE,
	ITM_RESIZE_FIGURE,
	ITM_ZOOM_IN,
	ITM_ZOOM_OUT,
	ITM_DELETE_FIGURE,
	ITM_MOVE_FIGURE,
	ITM_COPY_FIGURE,
	ITM_CUT_FIGURE,
	ITM_PASTE_FIGURE,
	ITM_SAVE_GRAPH,
	ITM_LOAD_GRAPH,
	ITM_SWITCH_TO_PLAY,
	ITM_EXITD,			//Exit item
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_GAME_TYPE,
	ITM_GAME_FILL_COLOR,
	ITM_GAME_FILL_TYPE,
	ITM_GAME_AREA,
	ITM_SWITCH_TO_DRAW,
	ITM_EXITP,
	//TODO: Add more items names here
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;

	int	width, height,	//Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed

}UI;	//create a global object UI

#endif