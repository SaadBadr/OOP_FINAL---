#include "SwitchToDrawAction.h"

#include"..\ApplicationManager.h"

#include <fstream>

SwitchToDrawAction::SwitchToDrawAction(ApplicationManager * pto) :Action(pto) {

	(LoadAction(pto,true,"0X0NULL")).Execute();


}

void SwitchToDrawAction::ReadActionParameters() {}

void SwitchToDrawAction::Execute() {
	Output*pOut = pManager->GetOutput();
	pOut->CreateDrawToolBar();
}

SwitchToDrawAction::~SwitchToDrawAction() {}
