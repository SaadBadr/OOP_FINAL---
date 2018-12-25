
#include "PickByFigure.h"
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
PickByFigure::PickByFigure(ApplicationManager* pto):Action(pto){
right = 0 ; wrong = 0;
}
	
void PickByFigure :: ReadActionParameters() 
{

Output* pOut = pManager->GetOutput();
Input* pIn = pManager->GetInput();
	
int foundFigures[5];
for(int i=0;i<5;i++){
	foundFigures[i]=0;
}

for(int i  = 0 ; i < pManager->getCount() ; i++){

	if(dynamic_cast<CLine*>((pManager->getFigList())[i])) foundFigures[0]++; 
	else if(dynamic_cast<CRectangle*>((pManager->getFigList())[i])) foundFigures[1]++;
	else if(dynamic_cast<CTriangle*>((pManager->getFigList())[i])) foundFigures[2]++;
	else if(dynamic_cast<CRhombus*>((pManager->getFigList())[i])) foundFigures[3]++; 
	else if(dynamic_cast<CEllipse*>((pManager->getFigList())[i])) foundFigures[4]++;


}



if(foundFigures[0]!=0 || foundFigures[1]!=0 || foundFigures[2]!=0 || foundFigures[3]!=0 || foundFigures[4]!=0){


int CorrectFigure = (rand() % 5); 
while( foundFigures[CorrectFigure] == 0 ){ CorrectFigure = (rand() % 5); } 

//0:line , 1: rectangle , 2 : triangle , 3 : rhombus , 4 : ellipse ! ;)

switch(CorrectFigure){

case 0 : pOut->PrintMessage("Pick all Lines!");
	break;
case 1 : pOut->PrintMessage("Pick all Rectangles!");
	break;
case 2 : pOut->PrintMessage("Pick all Triangles!");
	break;
case 3 : pOut->PrintMessage("Pick all Rhombuses!");
	break;
case 4 : pOut->PrintMessage("Pick all Ellipses!");
	break;

}

Point p;

while(right < foundFigures[CorrectFigure]){

	pIn->GetPointClicked(p.x, p.y);

	CFigure* f = pManager->GetFigure(p.x, p.y);

		if(f){

		int ChoosenFigure;
		if ( dynamic_cast<CLine*>(f)) ChoosenFigure = 0;
		else if ( dynamic_cast<CRectangle*>(f)) ChoosenFigure = 1;
		else if ( dynamic_cast<CTriangle*>(f)) ChoosenFigure = 2;
		else if ( dynamic_cast<CRhombus*>(f)) ChoosenFigure = 3;
		else if ( dynamic_cast<CEllipse*>(f)) ChoosenFigure = 4;

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
void PickByFigure :: Execute()
{
	ReadActionParameters();
}


