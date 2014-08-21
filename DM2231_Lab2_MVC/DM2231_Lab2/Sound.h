#pragma once
<<<<<<< HEAD
#include "../irrKlang/irrKlang.h"
=======
#include <irrKlang.h>
>>>>>>> origin/master

using namespace irrklang;

class Sound
{
public:
	/*
		Sound Type
	*/
	enum SoundType{
	MENU = 0,
	SUBPAGE,
	LEVEL,
	PISTOL,
	SHOTGUN,
	UZI,
	RELOAD,	
	EXPLOSION,
	HEALTH,
	AMMO,
	SLOWDOWN,
	SCORE,
	ZOMBIE,
	};

	Sound(void);
	~Sound(void);

	/*
		Sound engine
	*/
	ISoundEngine* theSoundEngine;
<<<<<<< HEAD
	ISound* Menu;
	ISound* Subpage;
	ISound* Level;
	ISound* Pistol;
	ISound* Shotgun;
	ISound* Uzi;
	ISound* Reload;
	ISound* Explosion;
	ISound* Health;
	ISound* Ammo;
	ISound* Slowdown;
	ISound* Score;
	ISound* Zombie;
=======
	ISound Menu;
	ISound Subpage;
	ISound Level;
	ISound Pistol;
	ISound Shotgun;
	ISound Uzi;
	ISound Reload;
	ISound Explosion;
	ISound Health;
	ISound Ammo;
	ISound Slowdown;
	ISound Score;
	ISound Zombie;
>>>>>>> origin/master

	/*
		Function to initialise all the sound
	*/
	bool InitSound(void);

	/*
		Function to play the sound
	*/
	void PlaySound (SoundType Sounds);


<<<<<<< HEAD
};
=======
};

>>>>>>> origin/master
