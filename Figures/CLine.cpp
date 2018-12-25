#include "CLine.h"
#include <fstream>

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{

	P1.y = P1.y >= UI.ToolBarHeight ? P1.y : UI.ToolBarHeight;
	P2.y = P2.y >= UI.ToolBarHeight ? P2.y : UI.ToolBarHeight;

	terminal[0] = P1;
	terminal[1] = P2;
}

void CLine::Draw(Output * pOut) const
{
	//Drawing a line on the drawing area...
	pOut->Drawline(terminal[0], terminal[1], FigGfxInfo, Selected);
}

bool CLine::Isinside(int x, int y)
{
	//rememmber that x-axis increasing towards rightside and y-axis towards downside
	double d1 = abs((x - terminal[0].x)*(x - terminal[0].x));
	double d2 = abs((y - terminal[0].y)*(y - terminal[0].y));
	double dist_to_start = sqrt(d1 + d2);

	double d3 = abs((x - terminal[1].x)*(x - terminal[1].x));
	double d4 = abs((y - terminal[1].y)*(y - terminal[1].y));
	double dist_to_end = sqrt(d3 + d4);

	double D1 = abs((terminal[0].x - terminal[1].x)*(terminal[0].x - terminal[1].x));
	double D2 = abs((terminal[0].y - terminal[1].y)*(terminal[0].y - terminal[1].y));
	double dist_form_two_ends = sqrt(D1 + D2);

	double dist_after__error1 = dist_to_start + dist_to_end + 10;
	double dist_after__error2 = dist_to_start + dist_to_end - 10;

	if (dist_form_two_ends <= dist_after__error1 && dist_form_two_ends >= dist_after__error2) {
		return true;
	}
	else {
		return false;
	}
}

Point* CLine::getPoints(){return terminal;}

bool CLine::isSelected(){
	if (Selected) {
		return true;
	}
	else {
		return false;
	}
}

void CLine :: Save (ofstream & save)
{
	int C[6] = { 1 , 2 , 3, 4 , 5 , 6} ;
	int DC ,FC ;

	if		( FigGfxInfo.DrawClr == WHITE ) DC =C[0] ;
	else if ( FigGfxInfo.DrawClr == BLACK ) DC =C[1];
	else if ( FigGfxInfo.DrawClr == RED )   DC =C[2];
	else if ( FigGfxInfo.DrawClr == GREEN ) DC =C[3];
	else if ( FigGfxInfo.DrawClr == BLUE )  DC =C[4];
	

	save<< "Line" <<"  "<<ID<<"   "<<terminal[0].x<<"  "<<terminal[0].y<<"  "<<terminal[1].x<<"  "<<terminal[1].y<<" "<<DC <<endl   ;
}

void CLine :: Load (ifstream & load) 
{
	int DC , FC ;

	load >> ID >>  terminal[0].x >> terminal[0].y >> terminal[1].x >> terminal[1].y >> DC  ;

	int C[6] = { 1 , 2 , 3, 4 , 5 , 6} ;

	if		(DC == C[0]) FigGfxInfo.DrawClr=WHITE;
	else if (DC == C[1]) FigGfxInfo.DrawClr=BLACK;
	else if	(DC == C[2]) FigGfxInfo.DrawClr=RED;
	else if (DC == C[3]) FigGfxInfo.DrawClr=GREEN;
	else if (DC == C[4]) FigGfxInfo.DrawClr=BLUE;

	FigGfxInfo.isFilled=false ;
}

CLine::~CLine(){}