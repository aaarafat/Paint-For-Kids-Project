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
void Input::GetEnterPressed() const
{
	char Key;
	while(true)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 13)
		{
			break;
		}

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
		if((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
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
		//[0] If user clicks on the Toolsbar

		if (x < UI.ToolBarHeight && y > UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight && UI.ToolBarMode == MODE_TOOL)
		{	
			//Check whick Tool item was clicked
			//==> This assumes that menu items are lined up vertically <==
			int ClickedItemOrder = (y / UI.ToolsItemHeight);
			//Divide y coord of the point clicked by the menu item width (int division)
			//if division result is 1 ==> first item is clicked, if 2 ==> 2nd item and so on

			switch (ClickedItemOrder-1) // -1 as the tool bar is under the menu bar so ther is 50px (1 after div) initially
			{
			case ITM_SELECT: return SELECT;
			case ITM_COPY: return COPY;
			case ITM_CUT: return CUT;
			case ITM_PASTE: return PASTE;
			case ITM_DELETE: return DEL;
			case ITM_SAVE: return SAVE;
			case ITM_SAVETYPE: return SAVE_BY_TYPE;
			case ITM_LOAD: return LOAD;
							
			
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
		if(x <= UI.ToolBarHeight && y > UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight && UI.ToolBarMode == MODE_CLR)
		{
			int ClickedItemOrder = (y / UI.ToolsItemHeight);
			switch (ClickedItemOrder - 1)
			{
			case CLR_BLACK: return CLR_BLACK_C;
			case CLR_WHITE: return CLR_WHITE_C;
			case CLR_RED: return CLR_RED_C;
			case CLR_GREEN: return CLR_GREEN_C;
			case CLR_BLUE: return CLR_BLUE_C;

			default: return EMPTY;
			}

		}

		//[1] If user clicks on the Toolbar
		if (y >= 0 && y <= UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_LINE: return DRAW_LINE;
			case ITM_TRI: return DRAW_TRI;
			case ITM_RHOMBUS: return DRAW_RHOMBUS;
			case ITM_ELIPSE: return DRAW_ELLIPSE;
			case ITM_CHNG_DRAW: return CHNG_DRAW_CLR;
			case ITM_CHNG_FILL: return CHNG_FILL_CLR;
			case ITM_SWITCH: return TO_PLAY;			
			case ITM_EXIT: return EXIT;	
			
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y <= UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case BY_TYPE: return CHOOSE_BYTYPE;
			case BY_COLOR: return CHOOSE_BYCOLOR;
			case PLY_ITM_EXIT: return EXIT;	
			case ITM_TODRAW: return TO_DRAW;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
		//[2]A click on empty place in the 2nd toolbar
		if(x <= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight && y > UI.ToolBarHeight)
		{
			return EMPTY;
		}

		//[3] User clicks on the playing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight && x >= UI.ToolBarHeight)
		{
			return PLAYING_AREA;	
		}
		
		//[4] User clicks on the status bar
		return STATUS;	
	}	

}
/////////////////////////////////
	
Input::~Input()
{
}
