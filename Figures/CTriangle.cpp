#include "CTriangle.h"
#include <fstream>

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{

	P1.y = P1.y >= UI.ToolBarHeight ? P1.y : UI.ToolBarHeight;
	P2.y = P2.y >= UI.ToolBarHeight ? P2.y : UI.ToolBarHeight;
	P3.y = P3.y >= UI.ToolBarHeight ? P3.y : UI.ToolBarHeight;
	vertices[0] = P1;
	vertices[1] = P2;
	vertices[2] = P3;
}

void CTriangle::Draw(Output * pOut) const
{
	pOut->DrawTriangle(vertices[0], vertices[1], vertices[2], FigGfxInfo, Selected);
}

bool CTriangle::Isinside(int x, int y) {
	double A1 = abs((0.5)*(x*(vertices[1].y - vertices[2].y) + y*(vertices[2].x - vertices[1].x) + (vertices[1].x * vertices[2].y - vertices[1].y * vertices[2].x)));
	double A2 = abs((0.5)*(x*(vertices[0].y - vertices[1].y) + y*(vertices[1].x - vertices[0].x) + (vertices[0].x * vertices[1].y - vertices[0].y * vertices[1].x)));
	double A3 = abs((0.5)*(x*(vertices[0].y - vertices[2].y) + y*(vertices[2].x - vertices[0].x) + (vertices[0].x * vertices[2].y - vertices[2].x * vertices[0].y)));

	double Triangle_Area = abs((0.5)*(vertices[0].x*(vertices[1].y - vertices[2].y) + vertices[0].y*(vertices[2].x - vertices[1].x) + (vertices[1].x * vertices[2].y - vertices[1].y * vertices[2].x)));

	double Total_Area = abs(A1) + abs(A2) + abs(A3);
	double Total_Area_after_error1 = Total_Area + 10;
	double Total_Area_after_error2 = Total_Area - 10;

	if (Triangle_Area <= Total_Area_after_error1 && Triangle_Area >= Total_Area_after_error2) {
		return true;
	}
	else {
		return false;
	}
}
void CTriangle::ChngFillClrState(bool c) {
	FigGfxInfo.isFilled = 1;
}

Point* CTriangle:: getPoints() {
	return vertices;
}

void CTriangle :: Save (ofstream & save)
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


	save<< "Triangle" <<" "<<ID <<" "<<vertices[0].x <<" " << vertices[0].y <<" " << vertices[1].x <<" " <<  vertices[1].y <<" "
		<< vertices[2].x <<" " << vertices[2].y<< " " <<DC<<" "<<FC << endl ;
}

void CTriangle :: Load ( ifstream & load ) 
{
	int DC , FC ;

	int C[6] = { 1 , 2 , 3, 4 , 5 , 6} ;

	load >> ID >> vertices[0].x >> vertices[0].y >> vertices[1].x >> vertices[1].y >> vertices[2].x >> vertices[2].y >>DC >>FC ;


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

CTriangle::~CTriangle(){}
