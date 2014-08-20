#pragma once
#include <irrKlang.h>

using namespace irrklang;

#pragma comment(lib, "irrKlang.lib")

class Sound
{
public:
	enum SoundType	{
	MENUPAGE = 0,
	SCOREPAGE,
	SUBPAGE,
	LEVEL,
	PISTOL,
	SHOTGUN,
	UZI,
	EXPLOSION,
	HEALTH,
	AMMO,
	SLOWDOWN,
	RELOAD,
	};

	Sound(void);
	~Sound(void);

	ISoundEngine* theSoundEngine;
	ISound Menupage;
	ISound Scorepage;
	ISound Subpage;
	ISound Level;
	ISound Pistol;
	ISound Shotgun;
	ISound Uzi;
	ISound Explosion;
	ISound Health;
	ISound Ammo;
	ISound Slowdown;
	ISound Reload;

	bool InitSound(void);

	void PlaySound(SoundType Sounds);
}