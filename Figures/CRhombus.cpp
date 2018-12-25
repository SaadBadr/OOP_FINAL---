#include "CRhombus.h"
#include <fstream>


CRhombus::CRhombus(Point P1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{	
	int h = 90; // h is the half of the vertical diagonal
	center[0] = P1;
	center[0].y = center[0].y >= UI.ToolBarHeight + h ? center[0].y : UI.ToolBarHeight + h;


}

void CRhombus::Draw(Output * pOut) const
{
	pOut->DrawRhombus(center[0], FigGfxInfo, Selected);
}

bool CRhombus::Isinside(int x, int y){
	// Rhombus function is : (x-x1)/a + (y-y1)/b = 1
	double result = (abs(center[0].x - x) / (120.0)) + (abs(center[0].y - y) / (180.0));
	if (result <= 0.5) {
		return true;
	}
	else {
		return false;
	}
}
Point* CRhombus::getPoints(){return center;}
bool CRhombus::isSelected()
{
	if (Selected) {
		return true;
	}
	else {
		return false;
	}
}

void CRhombus::ChngFillClrState(bool c) {
	FigGfxInfo.isFilled = 1;
}

void CRhombus:: Save  (ofstream & save) 
{
	int C[6] = { 1 , 2 , 3, 4 , 5 , 6} ;
	int DC ,FC ;

	if		( FigGfxInfo.DrawClr == WHITE ) DC =C[0] ;
	else if ( FigGfxInfo.DrawClr == BLACK ) DC =C[1];
	else if ( FigGfxInfo.DrawClr == RED )   DC =C[2];
	else if ( FigGfxInfo.DrawClr == GREEN ) DC =C[3];
	else if ( FigGfxInfo.DrawClr == BLUE )  DC =C[4];
	

	if(FigGfxInfo.isFilled == 0)			FC =C[5];
	else if ( FigGfxInfo.FillClr == WHITE )	FC =C[0] ;
	else if ( FigGfxInfo.FillClr == BLACK ) FC =C[1] ;
	else if ( FigGfxInfo.FillClr == RED )   FC =C[2] ;
	else if ( FigGfxInfo.FillClr == GREEN ) FC =C[3] ;
	else if ( FigGfxInfo.FillClr == BLUE )  FC =C[4] ;

	save << "Rhombus" <<" "<<ID<<" "<<center[0].x<<" "<<center[0].y<<" "<<DC <<" "<<FC <<endl ; //<<to_string(FigGfxInfo.DrawClr)  ;
}
	
void CRhombus:: Load (ifstream & load) 
{
	int DC , FC ;

	int C[6] = { 1 , 2 , 3, 4 , 5 , 6} ;

	load >> ID >> center[0].x >> center[0].y >> DC >>FC ;

	if		(DC == C[0]) FigGfxInfo.DrawClr=WHITE;
	else if (DC == C[1]) FigGfxInfo.DrawClr=BLACK;
	else if	(DC == C[2]) FigGfxInfo.DrawClr=RED;
	else if (DC == C[3]) FigGfxInfo.DrawClr=GREEN;
	else if (DC == C[4]) FigGfxInfo.DrawClr=BLUE;

	if		(FC == C[5]) FigGfxInfo.isFilled=0;
	else if (FC == C[0]) FigGfxInfo.FillClr =WHITE;
	else if (FC == C[1]) FigGfxInfo.FillClr =BLACK;
	else if	(FC == C[2]) FigGfxInfo.FillClr =RED;
	else if (FC == C[3]) FigGfxInfo.FillClr =GREEN;
	else if (FC == C[4]) FigGfxInfo.FillClr =BLUE;
}

CRhombus::~CRhombus(){}
