#include "SwitchToPlayAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Output.h"
#include "..\GUI\Input.h"
#include <fstream>

SwitchToPlayAction::SwitchToPlayAction(ApplicationManager * pto) :Action(pto) {

	(SaveAction(pto,true,"0X0NULL")).Execute();

}

void SwitchToPlayAction::ReadActionParameters() {


}

void SwitchToPlayAction::Execute() {
	Output*pOut = pManager->GetOutput();
	pOut->CreatePlayToolBar();
}

SwitchToPlayAction::~SwitchToPlayAction(void) {}
