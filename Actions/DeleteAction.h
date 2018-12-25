#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"


class DeleteAction : public Action
{
	bool implicit; CFigure* Figure;
public :
	DeleteAction ( ApplicationManager * p, bool i = false ,CFigure * F = NULL )  ;

	void ReadActionParameters() ;

	void Execute() ;

};