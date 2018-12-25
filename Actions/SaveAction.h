#pragma once

#include "..\GUI\UI_Info.h"
#include "Action.h"




class SaveAction : public Action
{
	bool implicit;
	string name;
public:

	SaveAction(ApplicationManager * pM,bool i = false ,string n= " ");

	void Execute() ;

	void ReadActionParameters() {}

};

