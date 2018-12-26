#include "select.h"
#include"..\ApplicationManager.h"
#include"..\Figures\CFigure.h"
#include"..\GUI\Output.h"
#include"..\GUI\Input.h"
#include"..\Figures\CLine.h"
#include"..\Figures\CEllipse.h"
#include"..\Figures\CRectangle.h"
#include"..\Figures\CRhombus.h"
#include"..\Figures\CTriangle.h"


AddSelectAction::AddSelectAction(ApplicationManager * ps):Action(ps){}

void AddSelectAction::ReadActionParameters(){
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("please select any figure");
	pIn->GetPointClicked(p.x, p.y);

	pOut->ClearStatusBar();
}

void AddSelectAction::Execute(){
	ReadActionParameters();
	CFigure* to_print;	
	CFigure* selected = pManager->GetFigure(p.x, p.y);
	string id_print;
	Point *ends;
	if (selected != NULL) { 
		id_print = to_string(selected->getID()); 
		ends = selected->getPoints();
	}
	string to_be_print[6];
	to_print = dynamic_cast<CLine*>(selected);
	if (to_print != NULL) {
		to_be_print[0] = to_string( ends[0].x);
		to_be_print[1] = to_string( ends[0].y);
		to_be_print[2] = to_string( ends[1].x);
		to_be_print[3] = to_string( ends[1].y);
		to_be_print[4] = to_string(0);
		to_be_print[5] = to_string(0);
	}
	to_print = dynamic_cast<CRectangle*>(selected);
	if (to_print != NULL) {
		to_be_print[0] = to_string(ends[0].x);
		to_be_print[1] = to_string(ends[0].y);
		to_be_print[2] = to_string(ends[1].x);
		to_be_print[3] = to_string(ends[1].y);
		to_be_print[4] = to_string(0);
		to_be_print[5] = to_string(0);
	}
	to_print = dynamic_cast<CTriangle*>(selected);
	if (to_print != NULL) {
		to_be_print[0] = to_string(ends[0].x);
		to_be_print[1] = to_string(ends[0].y);
		to_be_print[2] = to_string(ends[1].x);
		to_be_print[3] = to_string(ends[1].y);
		to_be_print[4] = to_string(ends[2].x);
		to_be_print[5] = to_string(ends[2].y);
	}
	to_print = dynamic_cast<CRhombus*>(selected);
	if (to_print != NULL) {
		to_be_print[0] = to_string(ends[0].x);
		to_be_print[1] = to_string(ends[0].y);
		to_be_print[2] = to_string(0);
		to_be_print[3] = to_string(0);
		to_be_print[4] = to_string(0);
		to_be_print[5] = to_string(0);
	}
	to_print = dynamic_cast<CEllipse*>(selected);
	if (to_print != NULL) {
		to_be_print[0] = to_string(ends[0].x);
		to_be_print[1] = to_string(ends[0].y);
		to_be_print[2] = to_string(0);
		to_be_print[3] = to_string(0);
		to_be_print[4] = to_string(0);
		to_be_print[5] = to_string(0);
	}

	if (selected != NULL) {
		if (pManager->getSelectedFig() == NULL) {
			selected->SetSelected(true);
			pManager->setSelectedFig(selected);
			pManager->GetOutput()->PrintMessage("ID:" + id_print + "  \t\t\t " + "P1(" + to_be_print[0] + "," + to_be_print[1] + ")" + "P2(" + to_be_print[2] + "," + to_be_print[3] + ")" + "P3(" + to_be_print[4] + "," + to_be_print[5] + ")");
		}
		else {
			if (pManager->getSelectedFig() == selected) {
				selected->SetSelected(false);
				pManager->setSelectedFig(NULL);
				pManager->GetOutput()->ClearStatusBar();
			}
			else {
				pManager->getSelectedFig()->SetSelected(false);
				selected->SetSelected(true);
				pManager->setSelectedFig(selected);
				pManager->GetOutput()->PrintMessage("ID:" + id_print + "  \t\t\t " + "P1(" + to_be_print[0] + "," + to_be_print[1] + ")" + "P2(" + to_be_print[2] + "," + to_be_print[3] + ")" + "P3(" + to_be_print[4] + "," + to_be_print[5] + ")");
			}
		}
	}
	else {
		if (pManager->getSelectedFig() != NULL) {
			pManager->getSelectedFig()->SetSelected(false);
			pManager->GetOutput()->ClearStatusBar();
		}
	}
}

AddSelectAction::~AddSelectAction(){}
