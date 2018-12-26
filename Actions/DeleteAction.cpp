#include "DeleteAction.h"


DeleteAction ::DeleteAction ( ApplicationManager * p,bool i ,CFigure * F ) : Action(p)
{
	implicit = i; Figure = F;
}


void  DeleteAction  :: ReadActionParameters()
{}

void DeleteAction  :: Execute() {
	pManager ->DelFigure(&implicit , Figure);
}
