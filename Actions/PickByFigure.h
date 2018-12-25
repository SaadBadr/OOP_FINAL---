#include "Action.h"

class PickByFigure : public Action
{
		int right, wrong;

public :

	PickByFigure(ApplicationManager* pto);

	void ReadActionParameters() ;

	void Execute();

};

