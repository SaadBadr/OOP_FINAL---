#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include"Actions\AddLineAction.h"
#include"Actions\AddEllipseAction.h"
#include"Actions\AddTriangleAction.h"
#include"Actions\AddRhombusAction.h"
#include"Actions\select.h"
#include"Actions\CopyFigAction.h"
#include"Actions\PasteFigAction.h"
#include"Actions\CutFigAction.h"
#include"Actions\SwitchToPlayAction.h"
#include"Actions\SwitchToDrawAction.h"
#include"Actions\ChnageDrawColorAction.h"
#include"Actions\ChangeFillColorAction.h"
#include"Actions\DeleteAction.h"
#include"Actions\PickByFigure.h"
#include"Actions\PickByColour.h"
#include"Actions\playSound.h"

//Constructor
ApplicationManager::ApplicationManager() : Clipboard(NULL),SelectedFig(NULL),SoundState(true)
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
	IsCutted = false;
	SelectedFig = NULL;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	//EX : User clicks on “Rectangle” icon in the toolbar  
	return pIn->GetUserAction();
}

void ApplicationManager:: setSoundState(bool s){SoundState = s;}
bool ApplicationManager:: getSoundState(){return SoundState;}

void ApplicationManager:: unCutLastFigure(){
	for(int i = 0 ; i < FigCount ; i++ )

		if(FigList[i]->isCutted()){
			FigList[i] ->SetCutted(false);
			FigList[i] ->unCut();
			break;
		}
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this); //Create Object of class AddRectAction 
			break;

		case DRAW_LINE:
			pAct = new AddLineAction(this); //Create Object of class AddLineAction 

			break;

		case DRAW_ELLIPSE:
			pAct = new AddEllipseAction(this);	//Create Object of class AddEllipseAction 

			break;
 
		case DRAW_RHOMBUS:
			pAct = new AddRhombusAction(this);	//Create Object of class AddRhombusAction 
			break;

		case DRAW_TRI:
			pAct = new AddTriangleAction(this);	//Create Object of class AddTriangleAction 
			
			break;

		case SELECT:
			pAct = new AddSelectAction(this);
			break;
		
		case DRAWING_AREA:
			break;

		case COPY : 
			pAct = new CopyFigAction(this);
			break;

		case PASTE : 
			pAct = new PasteFigAction(this);
			break;

		case CUT : 
			pAct = new CutFigAction(this);
			break;

		case CHNG_DRAW_CLR:
			pAct = new ChangeDrawColorAction(this);
			break;

		case CHNG_FILL_CLR:
			pAct = new ChangeFillColorAction(this);
			break;

		case SAVE :
			pAct =new SaveAction (this);
		
			break;

		case LOAD :
			pAct =new LoadAction (this);

			break;

		case DEL :
			pAct = new DeleteAction (this) ;

			break;

		case TO_PLAY:
			pAct = new SwitchToPlayAction(this);
			break;

		case PlayByFigure:
			pAct=new PickByFigure(this);
			break;
		
		case PlayByColour:
			pAct=new PickByColour(this);
			break;


		case TO_DRAW:
			pAct = new SwitchToDrawAction(this);
			break;

		case Sound:
			pAct = new playSound(this);
			break;

		case EXIT:
			return;

	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}

}

void ApplicationManager :: SaveAll(ofstream  & save)
{

	for (int i=0 ; i<FigCount ; i++)
		FigList[i]->Save( save );
}

CFigure **  ApplicationManager:: getFigList ()  
{
	return FigList ;
}

void ApplicationManager::setSelectedFig(CFigure * x){
	SelectedFig = x;
}


int & ApplicationManager:: getCount () 
{return FigCount ;}

CFigure * ApplicationManager::getSelectedFig() const
{
	return SelectedFig;
}

void ApplicationManager::setClipboard(CFigure * c){
	Clipboard = c;
}
CFigure * ApplicationManager::getClipboard() const
{
	return Clipboard;
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)

{
	if(FigCount < MaxFigCount )
	
{
	int max =0 ;
	for (int i =0 ; i < FigCount ; i++)
	{if (FigList[i] -> getID() >  max ) max =  FigList[i]->getID() ;}
		pFig->set_ID(max+1);
	

	pFig->set_ID(FigCount);
	
	FigList[FigCount++] = pFig;}

}

void ApplicationManager :: DelFigure(bool implicit, CFigure * Figure)
{

	pOut -> ClearStatusBar() ;

	CFigure * SF ;
	if(implicit) SF = Figure;

	else SF = SelectedFig ;

	int j;
	for (j=0 ;j < FigCount ; j++)
	{
		if (FigList[j] == SelectedFig || FigList[j] == SF)
		break;
	}

	if (SelectedFig == NULL && SF ==NULL ) pOut -> PrintMessage("No Figure is selected !") ;
		
	else
	{
		delete FigList[j];
		FigList[j]=NULL;SF=NULL;
		pOut -> ClearDrawArea();

		int n = FigCount ;								// by reference

		int y ;
		for (y =0 ; y < n ; y++)
		{
			if(FigList[y]==NULL) break ;
		}

		for (int i = y ;i < n-1 ; i++)
		{
			FigList[i] = FigList[i+1] ;
			FigList[i+1] =NULL ;
		}
		FigCount--;
		SelectedFig = NULL ;
	}
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	for (int i = FigCount-1; i>=0 ; i--) {
		if (FigList[i]->Isinside(x,y)) {
			return FigList[i];
		}
	}
	return NULL;
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	pOut->ClearDrawArea();
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
		//For each Figure in the list, call Draw function. Each Figure calls the appropriate draw function from Output class.
		//EX : CRectangle ::Draw calls Output::DrawRect -->> Rect. is shown

}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }

////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++) {
		delete FigList[i];
	}
	delete pIn;
	delete pOut;
	
}