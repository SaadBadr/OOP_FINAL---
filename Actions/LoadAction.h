#include "Action.h"

class LoadAction : public Action
{
	string name;
	bool implicit;

public :

	LoadAction ( ApplicationManager * pM, bool i = false ,string n = "" );

	void ReadActionParameters() ;

	void Execute();

};

