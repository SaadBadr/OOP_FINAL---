#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	Cutted = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::Isinside(int x, int y)
{
	return false;
}

bool CFigure::isSelected(){
	if (Selected) {
		return true;
	}
	else{
		return false;
	}
}
int CFigure :: getID() {return ID ;}


void CFigure::SetCutted(bool c)
{

Cutted = c; 
if(Cutted) GfxBeforeCut = FigGfxInfo;	

}

void CFigure::unCut()
{ 
	FigGfxInfo = GfxBeforeCut;

}



bool CFigure::isCutted(){

	return Cutted;

}


GfxInfo CFigure:: getGfxInfo() const{
return FigGfxInfo;
}

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

void CFigure :: set_ID(int i)
{ID = i ;}