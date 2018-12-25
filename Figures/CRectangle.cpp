#include "CRectangle.h"
#include <fstream>
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	P1.y = P1.y >= UI.ToolBarHeight ? P1.y : UI.ToolBarHeight;
	P2.y = P2.y >= UI.ToolBarHeight ? P2.y : UI.ToolBarHeight;
	Corner[0] = P1;
	Corner[1] = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner[0], Corner[1], FigGfxInfo, Selected);
}

bool CRectangle::Isinside(int x, int y){
	if (Corner[0].x < Corner[1].x) {	// "Corner[0]" is at left
		if ((x >= Corner[0].x && x <= Corner[1].x) && ((y >= Corner[0].y && y <= Corner[1].y) || (y <= Corner[0].y && y >= Corner[1].y))) {
			return true;
		}
		else {
			return false;
		}
	}

	else if (Corner[0].x > Corner[1].x) {	// "Corner[1]" is at left
		if ((x >= Corner[1].x && x <= Corner[0].x) && ((y >= Corner[1].y && y <= Corner[0].y) || (y <= Corner[1].y && y >= Corner[0].y))) {
			return true;
		}
		else {
			return false;
		}
	}
}


Point* CRectangle:: getPoints() {
return Corner;
}


bool CRectangle::isSelected()
{
	if (Selected) {
		return true;
	}
	else {
		return false;
	}

}

void CRectangle :: Save (ofstream & save)
{
	int C[6] = { 1 , 2 , 3, 4 , 5 , 6} ;
	int DC ,FC ;

	if		( FigGfxInfo.DrawClr == WHITE ) DC =C[0];
	else if ( FigGfxInfo.DrawClr == BLACK ) DC =C[1];
	else if ( FigGfxInfo.DrawClr == RED )   DC =C[2];
	else if ( FigGfxInfo.DrawClr == GREEN ) DC =C[3];
	else if ( FigGfxInfo.DrawClr == BLUE )  DC =C[4];
	

	if(FigGfxInfo.isFilled == 0)			FC =C[5];
	else if ( FigGfxInfo.FillClr == WHITE )	FC =C[0];
	else if ( FigGfxInfo.FillClr == BLACK ) FC =C[1];
	else if ( FigGfxInfo.FillClr == RED )   FC =C[2];
	else if ( FigGfxInfo.FillClr == GREEN ) FC =C[3];
	else if ( FigGfxInfo.FillClr == BLUE )  FC =C[4];

	save<< "Rectangle" <<" "<<ID <<" "<<Corner[0].x <<" " << Corner[0].y <<" " << Corner[1].x <<" " <<  Corner[1].y <<" "<<DC <<" "<<FC<<  endl ;
}



void CRectangle :: Load(ifstream & load)
{
	int DC , FC ;

	int C[6] = { 1 , 2 , 3, 4 , 5 , 6} ;

	load >> ID >> Corner[0].x >> Corner[0].y >> Corner[1].x >> Corner[1].y >>DC >>FC;

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