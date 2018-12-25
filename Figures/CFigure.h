#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include"..\GUI\Input.h"
#include "..\Actions\SaveAction.h"
#include "..\Actions\LoadAction.h"
//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	bool Cutted;
	GfxInfo FigGfxInfo,GfxBeforeCut;	//Figure graphis info
	color colorBeforeCut;	
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);
	GfxInfo getGfxInfo() const ;
	virtual Point* getPoints() = 0;
	void SetSelected(bool s);	//select/unselect the figure
	void SetCutted(bool c);
	virtual bool Isinside(int x,int y) ;	//check whether fig is selected
	virtual bool isSelected();
	virtual bool isCutted();
	virtual void unCut();
	int getID();
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color

	void set_ID(int);

	virtual void Save (ofstream &) =0;

	virtual void Load (ifstream & load) =0;

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	//virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif