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
	CFigure* FigList[MaxFigCount];

	CFigure* SelectedFig; //Pointer to the selected figure
	CFigure* Clipboard;   //Pointer to the copied/cut figure

						  //Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

	bool SoundState;

public:
	ApplicationManager();
	~ApplicationManager();
	bool getSoundState();
	void setSoundState(bool);
	void unCutLastFigure();
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType); //Creates an action and executes it
	void setSelectedFig(CFigure*x);	//set the Selected Figure to any figure
	void setClipboard(CFigure*c);	//set the Selected Figure to any figure
	CFigure* getSelectedFig() const;		//get the selected figure
	CFigure *getClipboard() const;
	void deleteCutted();
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	void DelFigure(bool, CFigure *);
	CFigure ** getFigList();
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	int & getCount();
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window
	void SaveAll(ofstream & save);
};

#endif