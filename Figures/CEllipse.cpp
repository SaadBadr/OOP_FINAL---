#include "CEllipse.h"
#include <fstream>


CEllipse::CEllipse(Point P1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo){
	P1.y = P1.y >= UI.ToolBarHeight + 40 ? P1.y : UI.ToolBarHeight + 40;
	center[0] = P1;
}

void CEllipse::Draw(Output * pOut) const
{
	pOut->DrawEllipse(center[0], FigGfxInfo, Selected);
}

bool CEllipse::Isinside(int x, int y) {
	//Ellipse equation : x^2/a^2 + y^2/b^2 = 1
	double result = ((abs((x - center[0].x))*abs((x - center[0].x))) / (10000.0)) + ((abs((y - center[0].y))*abs((y - center[0].y))) / (1600.0));
	if (result <= 1) { return true; }
	else { return false; }
}

Point* CEllipse::getPoints(){return center;}


bool CEllipse::isSelected(){
	if (Selected) {
		return true;
	}
	else {
		return false;
	}
}

void CEllipse:: Save (ofstream & save ) 
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
	save<< "Ellipse" << " " << ID << " " << center[0].x << " " <<  center[0].y <<" "<<DC <<" " <<FC <<  endl ;
}

void CEllipse:: Load (ifstream & load) 
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

CEllipse::~CEllipse(){}
