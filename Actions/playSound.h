#include "Action.h"

class playSound : public Action
{
	bool enableSound;

public :

	playSound(ApplicationManager* pto);

	void ReadActionParameters() ;

	void Execute();

};

