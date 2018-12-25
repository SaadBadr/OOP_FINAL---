#include "DeleteAction.h"


DeleteAction ::DeleteAction ( ApplicationManager * p,bool i ,CFigure * F ) : Action(p)
{
	implicit = i; Figure = F;
}


void  DeleteAction  :: ReadActionParameters()
{}

void DeleteAction  :: Execute() 
{
	//Input * pIn = pManager -> GetInput() ;
	//Output * pOut = pManager -> GetOutput() ;

	//pOut -> ClearStatusBar() ;
	//CFigure ** List = pManager->getFigList() ;					// by reference


	//CFigure * SF ;
	//if(implicit) SF = Figure;

	//else SF = pManager -> getSelectedFig() ;

	//int j;
	//for (j=0 ;j < pManager-> getCount() ; j++)
	//{
	//	if (List[j] == SF )
	//	break;
	//}

	//if (SF == NULL) pOut -> PrintMessage("No Figure is selected !") ;
	//	
	//else
	//{
	//	delete List[j];
	//	List[j]=NULL;

	//	pOut -> PrintMessage("Figure has been Deleted !") ;

	//	pOut -> ClearDrawArea();

	//	int n = pManager ->getCount() ;								// by reference

	//	int y ;
	//	for (y =0 ; y < n ; y++)
	//	{
	//		if(List[y]==NULL) break ;
	//	}

	//	for (int i = y ;i < n-1 ; i++)
	//	{
	//		List[i] = List[i+1] ;
	//		List[i+1] =NULL ;
	//	}
	//	pManager->getCount()--;
	//	pManager -> setSelectedFig (NULL);
	//}
	pManager ->DelFigure(&implicit , Figure);
}
