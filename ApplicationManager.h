#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "GUI\UI_Info.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures
	
private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* SelectedFig; //Pointer to the selected figure
	int S;	//Selected index in figlist
	CFigure* Clipboard;   //Pointer to the copied/cut figure
	bool filled;
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
	CFigure *GetFigure(int x, int y); //Search for a figure given a point inside the figure
	void setClipboard(CFigure *);
	CFigure * getClipboard() const;
	void DeleteFigure(CFigure* F);          //Delete figure
	void DeleteSelectedFigure();			//Removes a figure from the list and updates it
	void SaveAll(ofstream &OutFile, ofstream& colors, ofstream& figures);
	void LoadAll(ifstream &InFile);
	void SaveType(int type,ofstream& OutFile, ofstream& colors, ofstream& figures);
	void ReOrderList(bool front);
	void DelFigList();

	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	CFigure* GetSelected();
	void UpdateInterface() const;	//Redraws all the drawing window	
};

#endif