#include "Sound.h"
#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

Sound::Sound(void)
: theSoundEngine(NULL)
, Menupage(NULL)
, Scorepage(NULL)
, Subpage(NULL)
, Level(NULL)
, Pistol(NULL)
, Shotgun(NULL)
, Uzi(NULL)
, Explosion(NULL)
, Health(NULL)
, Ammo(NULL)
, Slowdown(NULL)
, Reload(NULL)
{
}

Sound::~Sound(void)
{
	if (theSoundEngine != NULL)
	{
		theSoundEngine->drop();
	}
}

bool Sound::InitSound(void)
{
	// Start the sound engine
	theSoundEngine = createIrrKlangDevice();
		if (!theSoundEngine)
			return false;			// Error starting up the sound engine
}

void Sound::RenderSound(SoundType Sounds)
{
	switch(Sounds)
	{
		case MENUPAGE:
			// Plays Menu sound
			if(Menupage == NULL)
			{
				Menupage = theSoundEngine->play2D(("sound/Menupage.wav"), false, true);
			}
			if (Menupage->getIsPaused() == true)
			{
				Menupage->setIsPaused(false);
			}
			else if (Menupage->isFinished() == true)
			{
				Menupage = NULL;
			}
			break;
		case SCOREPAGE:
			if(Scorepage == NULL)
			{
				Scorepage = theSoundEngine->play2D(("sound/Scorepage.wav"), false, true);
			}
			if (Scorepage->getIsPaused() == true)
			{
				Scorepage->setIsPaused(false);
			}
			else if (Scorepage->isFinished() == true)
			{
				Scorepage = NULL;
			}
			break;
		case SUBPAGE:
			if(Subpage == NULL)
			{
				Subpage = theSoundEngine->play2D(("sound/Subpage.wav"), false, true);
			}
			if (Subpage->getIsPaused() == true)
			{
				Subpage->setIsPaused(false);
			}
			else if (Subpage->isFinished() == true)
			{
				Subpage = NULL;
			}
			break;
		case LEVEL:
			if(Level == NULL)
			{
				Level = theSoundEngine->play2D(("sound/Level.wav"), false, true);
			}
			if (Level->getIsPaused() == true)
			{
				Level->setIsPaused(false);
			}
			else if (Level->isFinished() == true)
			{
				Level = NULL;
			}
			break;
		case PISTOL:
			if(Pistol == NULL)
			{
				Pistol = theSoundEngine->play2D(("sound/Pistol.wav"), false, true);
			}
			if (Pistol->getIsPaused() == true)
			{
				Pistol->setIsPaused(false);
			}
			else if (Pistol->isFinished() == true)
			{
				Pistol = NULL;
			}
			break;
		case SHOTGUN:
			if(Shotgun == NULL)
			{
				Shotgun = theSoundEngine->play2D(("sound/Shotgun.wav"), false, true);
			}
			if (Shotgun->getIsPaused() == true)
			{
				Shotgun->setIsPaused(false);
			}
			else if (Shotgun->isFinished() == true)
			{
				Shotgun = NULL;
			}
			break;
		case UZI:
			if(Uzi == NULL)
			{
				Uzi = theSoundEngine->play2D(("sound/Uzi.wav"), false, true);
			}
			if (Uzi->getIsPaused() == true)
			{
				Uzi->setIsPaused(false);
			}
			else if (Uzi->isFinished() == true)
			{
				Uzi = NULL;
			}
			break;
		case EXPLOSION:
			if(Explosion == NULL)
			{
				Explosion = theSoundEngine->play2D(("sound/Explosion.wav"), false, true);
			}
			if (Explosion->getIsPaused() == true)
			{
				Explosion->setIsPaused(false);
			}
			else if (Explosion->isFinished() == true)
			{
				Explosion = NULL;
			}
			break;
		case HEALTH:
			if(Health == NULL)
			{
				Health = theSoundEngine->play2D(("sound/Health.wav"), false, true);
			}
			if (Health->getIsPaused() == true)
			{
				Health->setIsPaused(false);
			}
			else if (Health->isFinished() == true)
			{
				Health = NULL;
			}
			break;
		case AMMO:
			if(Ammo == NULL)
			{
				Ammo = theSoundEngine->play2D(("sound/Ammo.wav"), false, true);
			}
			if (Ammo->getIsPaused() == true)
			{
				Ammo->setIsPaused(false);
			}
			else if (Ammo->isFinished() == true)
			{
				Ammo = NULL;
			}
			break;
		case SLOWDOWN:
			if(Slowdown == NULL)
			{
				Slowdown = theSoundEngine->play2D(("sound/Slowdown.wav"), false, true);
			}
			if (Slowdown->getIsPaused() == true)
			{
				Slowdown->setIsPaused(false);
			}
			else if (Slowdown->isFinished() == true)
			{
				Slowdown = NULL;
			}
			break;
		case RELOAD:
			if(Reload == NULL)
			{
				Reload = theSoundEngine->play2D(("sound/Reload.wav"), false, true);
			}
			if (Reload->getIsPaused() == true)
			{
				Reload->setIsPaused(false);
			}
			else if (Reload->isFinished() == true)
			{
				Reload = NULL;
			}
			break;
	default:
		break;
	}
}