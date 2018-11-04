#include "GUI\Input.h"
#include "GUI\Output.h"

//This is a test code to test the Input and Output classes

int main()
{
	int x,y;

	//Create Input and Output objects to test
	Output *pOut = new Output();
	Input *pIn = pOut->CreateInput();

	//Starting the test
	pOut->PrintMessage("This demo is to test input and output classes, Click anywhere to start the test");
	pIn->GetPointClicked(x,y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 1:	
	//			Create The FULL Tool bar, the drawing area and the status bar	
	//			This has already been done through the constrcutor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST1: Drawing Tool bar and Status bar, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	
	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	
	//			Drawing all the Figures with all possible states: 
	//			Non-filled, Filled, and highlighted in both cases			
	///////////////////////////////////////////////////////////////////////////////////
	
	pOut->PrintMessage("TEST2: Now we will show that Output class can draw any figure in any state, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	GfxInfo gfxInfo;//to be used with draw function of the class Ouput
	Point P1, P2, P3;

	/// 2.1- Rectangle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Rectangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	
	// 2.1.1 - Drawing non-filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> non-filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->CheckPoint(P1, pIn); //checking that the point's in the drawing area
	pIn->GetPointClicked(P2.x, P2.y);
	pOut->CheckPoint(P2, pIn); //checking that the point's in the drawing area

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawRect(P1, P2, gfxInfo, false);

	// 2.1.2 - Drawing highlighted non-filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->DrawRect(P1, P2, gfxInfo, true);


	// 2.1.3 - Drawing a filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->CheckPoint(P1, pIn);  //checking that the point's in the drawing area
	pIn->GetPointClicked(P2.x, P2.y);
	pOut->CheckPoint(P2, pIn);  //checking that the point's in the drawing area

	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.FillClr = GREEN;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->DrawRect(P1, P2, gfxInfo, false);


	// 2.1.4 - Drawing a highlighted filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->DrawRect(P1, P2, gfxInfo, true);



	pOut->PrintMessage("Drawing a Rectangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.2- Line Test ///
	/// ============== 
	pOut->PrintMessage("Drawing a Line, non highlighted/highlighted, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	// 2.2.1 - Drawing a Line
	pOut->PrintMessage("Drawing a Line ==> non-highlighted, click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->CheckPoint(P1, pIn);  //checking that the point's in the drawing area
	pIn->GetPointClicked(P2.x, P2.y);
	pOut->CheckPoint(P2, pIn);  //checking that the point's in the drawing area

	gfxInfo.isFilled = false;
	pOut->DrawL(P1, P2, gfxInfo, false);
	//2.2.2 - Drawing a highlighted Line
	pOut->PrintMessage("Drawing a Line ==> Highlighted, Click to Highlight");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->DrawL(P1, P2, gfxInfo, true);


	pOut->PrintMessage("Drawing a Line Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.3- Triangle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Triangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	// 2.3.1 - Drawing non-filled triangle
	pOut->PrintMessage("Drawing a Triangle ==> non-filled, click three points");
	pIn->GetPointClicked(P1.x,P1.y);
	pOut->CheckPoint(P1, pIn);  //checking that the point's in the drawing area
	pIn->GetPointClicked(P2.x,P2.y);
	pOut->CheckPoint(P2, pIn);  //checking that the point's in the drawing area
	pIn->GetPointClicked(P3.x,P3.y);
	pOut->CheckPoint(P3, pIn);  //checking that the point's in the drawing area
	gfxInfo.isFilled = false;
	pOut->DrawTri(P1, P2, P3, gfxInfo, false);

	// 2.3.2 - Drawing highlighted non-filled triangle
	pOut->PrintMessage("Drawing a Triangle ==> Highlighted non-filled, Click to highlight");
	pIn->GetPointClicked(x,y); //Wait for any click
	pOut->DrawTri(P1, P2, P3, gfxInfo, true);

	// 2.3.3 - Drawing a filled triangle
	pOut->PrintMessage("Drawing a Triangle ==> filled, click three points");
	pIn->GetPointClicked(P1.x,P1.y);
	pOut->CheckPoint(P1, pIn);  //checking that the point's in the drawing area
	pIn->GetPointClicked(P2.x,P2.y);
	pOut->CheckPoint(P2, pIn); //checking that the point's in the drawing area
	pIn->GetPointClicked(P3.x,P3.y);
	pOut->CheckPoint(P3, pIn); //checking that the point's in the drawing area
	gfxInfo.isFilled = true;
	pOut->DrawTri(P1, P2, P3, gfxInfo, false);

	//2.3.4 - Drawing a highlighted filled triangle
	pOut->PrintMessage("Drawing a Triangle ==> Highlighted filled, click to highlight");
	pIn->GetPointClicked(x,y); //checking that the point's in the drawing area
	pOut->DrawTri(P1, P2, P3, gfxInfo, true);
	pOut->PrintMessage("Drawing a Triangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();
	
	/// 2.4- Rhombus Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Rhombus, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	
	// 2.4.1 - Drawing a non-filled Rhombus
	pOut->PrintMessage("Drawing a Rhombus Test ==> non-filled, Click on the center");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->CheckPoint(P1, pIn);
	gfxInfo.isFilled = false;
	pOut->DrawRhom(P1, gfxInfo, false);
	// 2.4.2 - Drawing highlighted non filled Rhombus
	pOut->PrintMessage("Drawing a Rhombus Test ==> Highlighted non-filled, Click to highlight");
	pIn->GetPointClicked(x,y); //Waiting for any click
	pOut->DrawRhom(P1, gfxInfo, true);
	// 2.4.3 - Drawing a filled Rhombus
	pOut->PrintMessage("Drawing a Rhombus Test ==> filled, Click on the center");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->CheckPoint(P1, pIn); //checking that the point's in the drawing area
	gfxInfo.isFilled = true;
	pOut->DrawRhom(P1, gfxInfo, true);
	// 2.4.4 - Drawing a highlighted filled Rhombus
	pOut->PrintMessage("Drawing a Rhombus Test ==> Highlighted filled, click to highlight");
	pIn->GetPointClicked(x,y);
	pOut->DrawRhom(P1, gfxInfo, true);
	pOut->PrintMessage("Drawing a Rhombus Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();
	
	/// 2.5- Ellipse Test ///
	/// =================== 
	pOut->PrintMessage("Drawing an Ellipse, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	// 2.5.1 - Drawing non-filled Ellipse
	pOut->PrintMessage("Drawing a Ellipse Test ==> non-filled, click on the center");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->CheckPoint(P1, pIn); //checking that the point's in the drawing area
	gfxInfo.isFilled = false;
	pOut->DrawEli(P1, gfxInfo, false);
	// 2.5.2 - Drawing highlighted non-filled Ellipse
	pOut->PrintMessage("Drawing a Ellipse Test ==> Highlighted non-filled, click to highlight");
	pIn->GetPointClicked(x,y);
	pOut->DrawEli(P1, gfxInfo, true);
	// 2.5.3 - Drawing a filled Ellipse
	pOut->PrintMessage("Drawing a Ellipse Test ==> filled, click on the center");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->CheckPoint(P1, pIn); //checking that the point's in the drawing area
	gfxInfo.isFilled = true;
	pOut->DrawEli(P1, gfxInfo, false);
	// 2.5.4 - Drawing a highlighted filled Ellipse
	pOut->PrintMessage("Drawing a Ellipse Test ==> Highlighted filled, Click to highlight");
	pIn->GetPointClicked(x,y);
	pOut->DrawEli(P1, gfxInfo, true);

	

	pOut->PrintMessage("Drawing a Ellipse Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();
	
	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3: 
	//			Input Class: Read strings from the user
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST3: Now Time to test class Input, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	
	pOut->PrintMessage("Testing Input ability to read strings");
	string text = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
	pOut->PrintMessage("You Entered " + text);
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4: 
	//			Input Class : Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST4: Testing Input ability to detect User Action, click anywhere");

	ActionType ActType;
	
	do
	{
		ActType = pIn->GetUserAction();

		switch (ActType)
		{
		case DRAW_RECT:
				pOut->PrintMessage("Action: Draw a Rectangle , Click anywhere");
				break;

		case DRAW_LINE:
				pOut->PrintMessage("Action: Draw a Line , Click anywhere");
				break;

		case DRAW_RHOMBUS:
				pOut->PrintMessage("Action: Draw a Rhombus , Click anywhere");
				break;

		case DRAW_ELLIPSE:
				pOut->PrintMessage("Action: Draw an Ellipse , Click anywhere");
				break;

		case DRAW_TRI:
				pOut->PrintMessage("Action: Draw a Triangle , Click anywhere");
				break;

		case CHNG_DRAW_CLR:
				pOut->PrintMessage("Action: Change Figure's drawing color , Click anywhere");
				break;

		case CHNG_FILL_CLR:
				pOut->PrintMessage("Action: Change Figure's Fill color , Click anywhere");
				break;

		case CHOOSE_BYCOLOR:
			pOut->PrintMessage("Action: choose by color, Click anywhere");
			break;
		
		case CHOOSE_BYTYPE:
			pOut->PrintMessage("Action: choose by type, Click anywhere");
			break;

		case STATUS:
				pOut->PrintMessage("Action: a click on the Status Bar, Click anywhere");
				break;
 
		case DRAWING_AREA:
				pOut->PrintMessage("Action: a click on the Drawing Area, Click anywhere");
				break;
		
		case PLAYING_AREA:
			pOut->PrintMessage("Action: a click on the Playing Area, Click anywhere");
			break;

		case EMPTY:
				pOut->PrintMessage("Action: a click on empty area in the Design Tool Bar, Click anywhere");
				break;

		case TO_DRAW:
				pOut->PrintMessage("Action: Switch to Draw Mode, creating simualtion tool bar");
				pOut->CreateDrawToolBar();
				break;

		case TO_PLAY:
				pOut->PrintMessage("Action: Switch to Play Mode, creating Design tool bar");
				pOut->CreatePlayToolBar();
				break;
		case COPY:
				pOut->PrintMessage("Action: Copy, Click anywhere");
				break;
		case CUT:
				pOut->PrintMessage("Action: CUT, Click anywhere");
				break;
		case PASTE:
				pOut->PrintMessage("Action: Paste, Click anywhere");
				break;
		case DEL:
				pOut->PrintMessage("Action: Delete, Click anywhere");
				break;
		case SAVE:
				pOut->PrintMessage("Action: Save, Click anywhere");
				break;
		case SAVE_BY_TYPE:
				pOut->PrintMessage("Action: Save By Type, Click anywhere");
				break;
		case LOAD:
				pOut->PrintMessage("Action: LOAD, Click anywhere");
				break;
		case EXIT:				
				break;
		}
	}while(ActType != EXIT);


	/// Exiting
	pOut->PrintMessage("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(x,y);


	delete pIn;
	delete pOut;	
	return 0;
}


