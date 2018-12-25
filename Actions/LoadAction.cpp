#include <fstream>
#include"..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\Figures\CFigure.h"
#include "AddLineAction.h"
#include "AddTriangleAction.h"
#include "..\Figures\CRectangle.h"
#include "AddLineAction.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CRhombus.h"
#include "..\Figures\CEllipse.h"
#include "..\Figures\CTriangle.h"





LoadAction :: LoadAction ( ApplicationManager * pM,bool i,string n):Action (pM), implicit(i) , name(n)
{}

void LoadAction :: ReadActionParameters() 
{
	Input* pIn = pManager->GetInput();
	Output*pOut= pManager-> GetOutput();
	string FileName ;

	if(implicit){

	pOut ->ClearStatusBar();
	pOut -> ClearDrawArea();

	FileName = name;
} 
	else{
	pOut->PrintMessage( "Please click anywhere then write the file's name in the status bar " );
	int x ,y ;
	pIn->GetPointClicked(x,y);
	pOut -> ClearStatusBar() ;
	
	FileName = pIn->GetSrting(pOut);
	pOut -> ClearDrawArea();
	
	pOut->ClearStatusBar();

	}
		CFigure ** f = pManager->getFigList();
	for(int i = 0 ;  i < pManager->getCount() ; i++){ 
		delete f[i];


}

	(pManager ->getCount()) = 0;


	//pManager->getCount() = 0;
	ifstream load ;
	load.open(FileName);

	int DC  , FC ;
	load>>DC >>FC ;
	int C[6] = { 1 , 2 , 3, 4 , 5 , 6} ;

	if		( DC == 1) UI.DrawColor=WHITE ;
	else if ( DC == 2) UI.DrawColor=BLACK ;
	else if ( DC == 3) UI.DrawColor=RED   ;
	else if ( DC == 4) UI.DrawColor=GREEN ;
	else if ( DC == 5) UI.DrawColor=BLUE  ;
	

	if		( FC == 1) UI.FillColor = UI.FillColor=WHITE ;
	else if ( FC == 2) UI.FillColor = UI.FillColor=BLACK ;
	else if ( FC == 3) UI.FillColor = UI.FillColor=RED   ;
	else if ( FC == 4) UI.FillColor = UI.FillColor=GREEN ;
	else if ( FC == 5) UI.FillColor = UI.FillColor=BLUE  ;

	int numFig ;
	load >> numFig;

	string type;
	while (load >> type )

	{	if (type == "Line") 
		{	 Point p1 ,p2; GfxInfo LGFX ;  CLine * CL = new CLine(p1,p2,LGFX);   CL->Load( load )  ; 
			 pManager ->AddFigure(CL );
		}



		else if ( type == "Triangle" )
		{   Point p1 ,p2 , p3; GfxInfo TGFX ; CTriangle*CT=new CTriangle (p1, p2, p3, TGFX); CT->Load( load );
			pManager ->AddFigure ( CT )  ;
		} 
										
		

		else if ( type == "Rectangle" )
		{
			Point p1 ,p2; GfxInfo RGFX ;  CRectangle * CR = new CRectangle (p1,p2,RGFX);   CR->Load( load )  ;
			pManager ->AddFigure(CR );		
		}

	
		else if ( type == "Rhombus" )	
		{
			Point p1 ; GfxInfo RHGFX ; CRhombus * CRH = new CRhombus (p1 , RHGFX)  ; CRH ->Load (load);
			pManager -> AddFigure( CRH ) ;
		}
			
		else if ( type == "Ellipse" )
		{
			Point p1 ; GfxInfo EGFX ; CEllipse * CE = new CEllipse (p1 , EGFX)  ; CE ->Load (load);
			pManager -> AddFigure( CE ) ;
		}		
	
	}
}

void LoadAction :: Execute()
{
	ReadActionParameters();
}


