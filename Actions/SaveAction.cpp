#include "SaveAction.h"
#include "..\ApplicationManager.h"
#include "..\DEFS.h"
#include <fstream>


//NOTE : if this function is used implicitly will be true and other parameter will passed,, else the function will act normally :) 

SaveAction::SaveAction(ApplicationManager * pM, bool i,string n) : Action(pM) , implicit(i) , name(n)
{}

void SaveAction:: Execute() 
{
	string FileName;
	Input * pIn = pManager->GetInput();
	Output * pOut = pManager->GetOutput();	

	
	ofstream save;

	if(implicit){
	pOut ->ClearStatusBar();
	FileName = name;
}
	
	else{
		
		

	pOut -> PrintMessage("Please , click anywhere then write the filename");
	
	int x, y ;
	pIn -> GetPointClicked(x,y);
	pOut ->ClearStatusBar();


	FileName = pIn -> GetSrting( pOut );
	
	
	}

	save.open (FileName);



	int DC ,FC ;
	int C[6] = { 1 , 2 , 3, 4 , 5 , 6} ;

	if		( UI.DrawColor == WHITE) DC =C[0] ;
	else if ( UI.DrawColor == BLACK) DC =C[1];
	else if ( UI.DrawColor == RED)   DC =C[2];
	else if ( UI.DrawColor == GREEN) DC =C[3];
	else if ( UI.DrawColor == BLUE)  DC =C[4];
	

	if		( UI.FillColor == WHITE)  FC =C[0];
	else if ( UI.FillColor == BLACK)  FC =C[1] ;
	else if ( UI.FillColor == RED)	  FC =C[2] ;
	else if ( UI.FillColor == GREEN)  FC =C[3] ;
	else if ( UI.FillColor == BLUE)   FC =C[4] ;
	
	save << DC << " "<<FC << endl ;

	save << pManager-> getCount()   << endl ; 

	pManager -> SaveAll(save);

	save.close();
	
	pOut -> ClearStatusBar();
}