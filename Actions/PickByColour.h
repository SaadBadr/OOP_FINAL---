#include "Action.h"

class PickByColour : public Action
{
		int right, wrong;

public :

	PickByColour(ApplicationManager* pto);

	void ReadActionParameters() ;

	void Execute();

};

