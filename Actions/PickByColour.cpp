
#include "PickByColour.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CEllipse.h"
#include "..\Figures\CFigure.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CRhombus.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CTriangle.h"
#include "DeleteAction.h"
#include <ctime>
PickByColour::PickByColour(ApplicationManager* pto):Action(pto){
right = 0 ; wrong = 0;
}
	
void PickByColour :: ReadActionParameters() 
{

Output* pOut = pManager->GetOutput();
Input* pIn = pManager->GetInput();
	
int foundFigures[5];
for(int i=0;i<5;i++){
	foundFigures[i]=0;
}

for(int i  = 0 ; i < pManager->getCount() ; i++){
	
	if( (pManager->getFigList()) &&  ((pManager->getFigList())[i]->getGfxInfo()).FillClr == WHITE) foundFigures[0]++; 
	else if( (pManager->getFigList()[i])->getGfxInfo().isFilled && ((pManager->getFigList())[i]->getGfxInfo()).FillClr == BLACK) foundFigures[1]++;
	else if( (pManager->getFigList()[i])->getGfxInfo().isFilled &&  ((pManager->getFigList())[i]->getGfxInfo()).FillClr == RED) foundFigures[2]++;
	else if( (pManager->getFigList()[i])->getGfxInfo().isFilled && ((pManager->getFigList())[i]->getGfxInfo()).FillClr == BLUE) foundFigures[3]++; 
	else if( (pManager->getFigList()[i])->getGfxInfo().isFilled &&  ((pManager->getFigList())[i]->getGfxInfo()).FillClr == GREEN) foundFigures[4]++;
	
}



if(foundFigures[0]!=0 || foundFigures[1]!=0 || foundFigures[2]!=0 || foundFigures[3]!=0 || foundFigures[4]!=0){


int CorrectFigure = (rand() % 5); 
while( foundFigures[CorrectFigure] == 0 ){ CorrectFigure = (rand() % 5); } 

//0:WHITE , 1: BLACK , 2 : RED , 3 : BLUE , 4 : GREEN ! ;)

switch(CorrectFigure){

case 0 : pOut->PrintMessage("Pick all White Figure!");
	break;
case 1 : pOut->PrintMessage("Pick all Black Figures!");
	break;
case 2 : pOut->PrintMessage("Pick all Red Figures!");
	break;
case 3 : pOut->PrintMessage("Pick all Blue Figures!");
	break;
case 4 : pOut->PrintMessage("Pick all Green Figures!");
	break;

}

Point p;

while(right < foundFigures[CorrectFigure]){

	pIn->GetPointClicked(p.x, p.y);

	CFigure* f = pManager->GetFigure(p.x, p.y);

		if(f){

		int ChoosenFigure;
		if ( ((f->getGfxInfo()).isFilled) && (f->getGfxInfo()).FillClr == WHITE ) ChoosenFigure = 0;
		else if ( ((f->getGfxInfo()).isFilled  ) && (f->getGfxInfo()).FillClr == BLACK ) ChoosenFigure = 1;
		else if ( ((f->getGfxInfo()).isFilled) && (f->getGfxInfo()).FillClr ==  RED) ChoosenFigure = 2;
		else if (((f->getGfxInfo()).isFilled) &&  (f->getGfxInfo()).FillClr == BLUE ) ChoosenFigure = 3;
		else if ( ((f->getGfxInfo()).isFilled) && (f->getGfxInfo()).FillClr == GREEN ) ChoosenFigure = 4;
		else if (! ((f->getGfxInfo()).isFilled) ) ChoosenFigure = 5;

		(DeleteAction(pManager,true,f)).Execute();
		pManager->UpdateInterface();

		if(ChoosenFigure == CorrectFigure) {
			right++;

		}
		else wrong++;
		}
	}
	string correct=to_string(right);
	string incorrect=to_string(wrong);

	pOut->PrintMessage(" correct : "+correct+ +"\t \t incorrect : "+incorrect);
}

}
void PickByColour :: Execute()
{
	ReadActionParameters();
}


