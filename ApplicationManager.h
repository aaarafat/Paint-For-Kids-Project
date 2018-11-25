#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures
	
private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	color LastDrwClr;               //Last Draw Color for the cutted figure
	CFigure* SelectedFig; //Pointer to the selected figure
	CFigure* Clipboard;   //Pointer to the copied/cut figure
	CFigure* pCut;        //Pointer to the cut figure
	bool filled;
	bool IsCut; //checks if the figure is cut
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	void AddSelected(CFigure* S);
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void setClipboard(CFigure *);
	CFigure * getClipboard() const;
	bool IsCutted() const;                  //Checks if the figure is cut/copy
   	void ChngCutMode(bool);						//Change IsCut to true 
	void DeleteFigure(CFigure* F);          //Delete figure
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	CFigure* GetSelected();
	void UpdateInterface() const;	//Redraws all the drawing window	
	void setLastDrwClr(color LastDrwClr);  //sets the last draw color for the cutted figure
	color getLastDrwClr();				//gets the last draw color for the cutted figure
	void SetpCut(CFigure*);             //sets the cut pointer
	CFigure* GetpCut();                 //sets the cut pointer
};

#endif