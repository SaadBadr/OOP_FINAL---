#include "playSound.h"
#include "../ApplicationManager.h"
playSound::playSound(ApplicationManager * pR ):Action(pR)
{

}


void playSound::ReadActionParameters(){

	enableSound = pManager->getSoundState();
	
}


void playSound::Execute()
{

	ReadActionParameters();
	enableSound = !enableSound;
	if(enableSound) pManager->GetOutput()->PrintMessage("Sound Enabled !");
	else pManager->GetOutput()->PrintMessage("Sound Disabled !"); 
	pManager->setSoundState(enableSound);
}

