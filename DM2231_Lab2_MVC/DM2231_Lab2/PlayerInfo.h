#pragma once
#include "Header.h"
<<<<<<< HEAD
//#include "TextureImage.h"
=======

>>>>>>> origin/master

class CPlayerInfo
{
public:
	CPlayerInfo(void);
	~CPlayerInfo(void);

	//TextureImage HeroTexture[3];

	// Render the Hero onto the screen
	void RenderHero(void);

	// Initialise this class instance
	void Init(void);

	// Set position x of the player
	void SetPos_x(int pos_x);

	// Set position y of the player
	void SetPos_y(int pos_y);

	// Get position x of the player
	int GetPos_x(void);
	// Get position y of the player
	int GetPos_y(void);

	// Set Animation Invert status of the player
	void SetAnimationInvert(bool heroAnimationInvert);
	// Get Animation Invert status of the player
	bool GetAnimationInvert(void);
	// Set Animation Counter of the player
	void SetAnimationCounter(int heroAnimationCounter);
	// Get Animation Counter of the player
	int GetAnimationCounter(void);

	// Constrain the position of the Hero to within the border
	void ConstrainHero(const int leftBorder, const int rightBorder, 
					   const int topBorder, const int bottomBorder, 
					   float timeDiff,
					   int& mapOffset_x, int& mapOffset_y);

	int m_iTileSize;
	int movementspeed;

private:
	

	// Hero's information
	int hero_x, hero_y;

	bool heroAnimationInvert;
	int heroAnimationCounter;

	
};
