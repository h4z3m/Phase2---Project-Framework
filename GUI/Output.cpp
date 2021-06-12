#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;


	UI.width = 1390;
	UI.height = 650;
	UI.wx = 150;
	UI.wy = 150;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 70;
	UI.MenuItemWidth = 60;

	UI.DrawColor = FinalStTX;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = FinalStTX;		//Messages color
	UI.BkGrndColor = FinalBG;	//Background color
	UI.HighlightColor = FinalHGIH;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = FinalStBG;
	UI.PenWidth = 3;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();


}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);


}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	//`~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\ITM_RECT.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\ITM_CIRC.jpg";
	MenuItemImages[ITM_LINE] = "images\\MenuItems\\ITM_LINE.jpg";
	MenuItemImages[ITM_TRIANGLE] = "images\\MenuItems\\ITM_TRIANGLE.jpg";
	MenuItemImages[ITM_ACT_UNDO] = "images\\MenuItems\\undo.jpg";
	MenuItemImages[ITM_ACT_REDO] = "images\\MenuItems\\redo.jpg";
	MenuItemImages[ITM_SEND_TO_BACK] = "images\\MenuItems\\sendback.jpg";
	MenuItemImages[ITM_BRING_TO_FRONT] = "images\\MenuItems\\bringfront.jpg";
	MenuItemImages[ITM_ROTATE_FIGURE] = "images\\MenuItems\\rotate.jpg";
	MenuItemImages[ITM_CHANGE_COLOR] = "images\\MenuItems\\color.jpg";
	MenuItemImages[ITM_SELECT_FIGURE] = "images\\MenuItems\\select.jpg";
	MenuItemImages[ITM_RESIZE_FIGURE] = "images\\MenuItems\\resize.jpg";
	MenuItemImages[ITM_ZOOM_IN] = "images\\MenuItems\\zoomin.jpg";
	MenuItemImages[ITM_ZOOM_OUT] = "images\\MenuItems\\zoomout.jpg";
	MenuItemImages[ITM_DELETE_FIGURE] = "images\\MenuItems\\delete.jpg";
	MenuItemImages[ITM_MOVE_FIGURE] = "images\\MenuItems\\move.jpg";
	MenuItemImages[ITM_COPY_FIGURE] = "images\\MenuItems\\copy.jpg";
	MenuItemImages[ITM_CUT_FIGURE] = "images\\MenuItems\\cut.jpg";
	MenuItemImages[ITM_PASTE_FIGURE] = "images\\MenuItems\\paste.jpg";
	MenuItemImages[ITM_SAVE_GRAPH] = "images\\MenuItems\\save.jpg";
	MenuItemImages[ITM_LOAD_GRAPH] = "images\\MenuItems\\load.jpg";
	MenuItemImages[ITM_SWITCH_TO_PLAY] = "images\\MenuItems\\playmode.jpg";
	MenuItemImages[ITM_EXITD] = "images\\MenuItems\\Menu_Exit.jpg";
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//TODO: Prepare images for each menu item and add it to the list

	//Clear play toolbar
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, 24 * UI.MenuItemWidth, 70, FILLED);

	////////////////////////////************ NEW INTERFACE *************//////////////////////////////

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(FinalStBG, 3); //line under tool bar when creating draw tool bar
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

	////////////////////////////************ NEW INTERFACE *************//////////////////////////////

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;

	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_GAME_TYPE] = "images\\MenuItems\\game_type.jpg";
	MenuItemImages[ITM_GAME_FILL_COLOR] = "images\\MenuItems\\game_color.jpg";
	MenuItemImages[ITM_GAME_FILL_TYPE] = "images\\MenuItems\\game_type_color.jpg";
	MenuItemImages[ITM_GAME_AREA] = "images\\MenuItems\\game_area.jpg";
	MenuItemImages[ITM_SWITCH_TO_DRAW] = "images\\MenuItems\\drawmode.jpg";
	MenuItemImages[ITM_EXITP] = "images\\MenuItems\\Menu_Exit.jpg";

	//Clear draw toolbar
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, 24 * UI.MenuItemWidth, 70, FILLED);

	//Draw play toolbar menu items
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(FinalStBG, 3); //line under tool bar when creating draw tool bar
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);


	///TODO: write code to create Play mode menu
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(FinalBG, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}


//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drwawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

string Output::getColorName(color& CLR) {
	if (CLR == BLACK) {
		return "BLACK";
	}
	else if (CLR == WHITE) {
		return "WHITE";

	}
	else if (CLR == RED) {
		return "RED";

	}
	else if (CLR == GREEN) {
		return "GREEN";

	}
	else if (CLR == BLUE) {
		return "BLUE";

	}
	else if (CLR == YELLOW) {
		return "YELLOW";

	}
	else if (CLR == AQUAMARINE) {
		return "AQUAMARINE";

	}
	else if (CLR == LIGHTGOLDENRODYELLOW) {
		return "LIGHTGOLDENRODYELLOW";
	}
	else if (CLR == FinalBG) {
		return "FinalBG";
	}
	return "NO_FILL";
}
color Output::getColorObj(string str)
{
	if (str == "BLACK") {
		return BLACK;
	}
	else if (str == "WHITE") {
		return WHITE;

	}
	else if (str == "RED") {
		return RED;

	}
	else if (str == "GREEN") {
		return GREEN;

	}
	else if (str == "BLUE") {
		return BLUE;

	}
	else if (str == "YELLOW") {
		return YELLOW;

	}
	else if (str == "AQUAMARINE") {
		return AQUAMARINE;

	}
	else if (str == "LIGHTGOLDENRODYELLOW") {
		return LIGHTGOLDENRODYELLOW;
	}
	else if (str == "FinalBG") {
		return FinalBG;
	}
	return UI.FillColor;
}
//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//
// -- GILANY GILANY GILANY GILANY GILANY GILANY GILANY GILANY GILANY GILANY

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
}

void Output::DrawTri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected) const {

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, TriGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}
void Output::DrawCir(Point P1, Point P2, GfxInfo CirGfxInfo, bool selected) const {

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CirGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, CirGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (CirGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CirGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawCircle(P1.x, P1.y, sqrt(pow(P2.x - P1.x, 2) + pow(P2.y - P1.y, 2) * 1.0), style);


}

void Output::DrawLin(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected) const {

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = LineGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, LineGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (LineGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(LineGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);


}	// -- GILANY GILANY GILANY GILANY GILANY GILANY GILANY GILANY GILANY

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

