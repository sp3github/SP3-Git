#include "PlayerInfo.h"
#include <iostream>

CPlayerInfo::CPlayerInfo(void)
{
}

CPlayerInfo::~CPlayerInfo(void)
{
}

// Initialise this class instance
void CPlayerInfo::Init(void)
{
	m_iTileSize = 24;
	burn = false;
	hero_x = 100;
	hero_y = 300;
	jumpspeed = 0;
	hero_inMidAir_Up = false;
	hero_inMidAir_Down = false;
	heroAnimationCounter = 0;
	heroAnimationInvert = false;
	movementspeed = 5;
}

/****************************************************************************************************
   Draw the hero
 ****************************************************************************************************/
void CPlayerInfo::RenderHero(void) {
	glPushMatrix();
	glTranslatef(hero_x, hero_y, 0);
	glEnable( GL_TEXTURE_2D );
	glEnable( GL_BLEND );
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		if (heroAnimationInvert == false)
		{	
			//glBindTexture(GL_TEXTURE_2D, HeroTexture[1].texID);
			glBegin(GL_QUADS);
 
			glTexCoord2f(0.25 * heroAnimationCounter, 1); glVertex2f(0, 0);
			glTexCoord2f(0.25 * heroAnimationCounter, 0); glVertex2f(0, m_iTileSize);
			glTexCoord2f(0.25 * heroAnimationCounter + 0.24, 0); glVertex2f(m_iTileSize, m_iTileSize);
			glTexCoord2f(0.25 * heroAnimationCounter + 0.24, 1); glVertex2f(m_iTileSize, 0);
			glEnd();
		}
		else
		{
			//glBindTexture(GL_TEXTURE_2D, HeroTexture[1].texID);
			glBegin(GL_QUADS);
			glTexCoord2f(0.25 * heroAnimationCounter + 0.24,1); glVertex2f(0,0);
			glTexCoord2f(0.25 * heroAnimationCounter + 0.24,0); glVertex2f(0,m_iTileSize);
			glTexCoord2f(0.25 * heroAnimationCounter,0); glVertex2f(m_iTileSize,m_iTileSize);
			glTexCoord2f(0.25 * heroAnimationCounter,1); glVertex2f(m_iTileSize,0);
			glEnd();
		}

		if (burn == true)
		{
			glColor4f(1, 1, 1, 0.7);
			//glBindTexture(GL_TEXTURE_2D, HeroTexture[2].texID);
			glBegin(GL_QUADS);
			glTexCoord2f(0.2 * heroAnimationCounter, 1); glVertex2f(0, 0);
			glTexCoord2f(0.2 * heroAnimationCounter, 0); glVertex2f(0, m_iTileSize);
			glTexCoord2f(0.2 * heroAnimationCounter + 0.19, 0) ; glVertex2f(m_iTileSize, m_iTileSize);
			glTexCoord2f(0.2 * heroAnimationCounter + 0.19, 1); glVertex2f(m_iTileSize, 0);
			glEnd();
		}

	glEnd();
	glDisable( GL_BLEND );
	glDisable( GL_TEXTURE_2D );
	glPopMatrix();
}

// Returns true if the player is on ground
bool CPlayerInfo::isOnGround(void)
{
	if (hero_inMidAir_Up == false && hero_inMidAir_Down == false)
		return true;

	return false;
}

// Returns true if the player is jumping upwards
bool CPlayerInfo::isJumpUpwards(void)
{
	if (hero_inMidAir_Up == true && hero_inMidAir_Down == false)
		return true;

	return false;
}

// Returns true if the player is on freefall
bool CPlayerInfo::isFreeFall(void)
{
	if (hero_inMidAir_Up == false && hero_inMidAir_Down == true)
		return true;

	return false;
}

// Set the player's status to free fall mode
void CPlayerInfo::SetOnFreeFall(bool isOnFreeFall)
{
	if (isOnFreeFall == true)
	{
		hero_inMidAir_Up = false;
		hero_inMidAir_Down = true;
		jumpspeed = 0;
	}
}

// Set the player to jumping upwards
void CPlayerInfo::SetToJumpUpwards(bool isOnJumpUpwards)
{
	if (isOnJumpUpwards == true)
	{
		hero_inMidAir_Up = true;
		hero_inMidAir_Down = false;
		jumpspeed = 15;
	}
}

// Set position x of the player
void CPlayerInfo::SetPos_x(int pos_x)
{
	hero_x = pos_x;
}

// Set position y of the player
void CPlayerInfo::SetPos_y(int pos_y)
{
	hero_y = pos_y;
}

// Set Jumpspeed of the player
void CPlayerInfo::SetJumpspeed(int jumpspeed)
{
	this->jumpspeed = jumpspeed;
}

// Stop the player's movement
void CPlayerInfo::SetToStop(void)
{
	hero_inMidAir_Up = false;
	hero_inMidAir_Down = false;
	jumpspeed = 0;
}

// Get position x of the player
int CPlayerInfo::GetPos_x(void)
{
	return hero_x;
}

// Get position y of the player
int CPlayerInfo::GetPos_y(void)
{
	return hero_y;
}

// Get Jumpspeed of the player
int CPlayerInfo::GetJumpspeed(void)
{
	return jumpspeed;
}

// Update Jump Upwards
void CPlayerInfo::UpdateJumpUpwards()
{
	hero_y -= jumpspeed;
	jumpspeed -= 1;
	if (jumpspeed == 0)
	{
		burn = false;
		hero_inMidAir_Up = false;
		hero_inMidAir_Down = true;
	}
}

// Update FreeFall
void CPlayerInfo::UpdateFreeFall()
{
	hero_y += jumpspeed;
	jumpspeed += 1;
}

// Set Animation Invert status of the player
void CPlayerInfo::SetAnimationInvert(bool heroAnimationInvert)
{
	this->heroAnimationInvert = heroAnimationInvert;
}
// Get Animation Invert status of the player
bool CPlayerInfo::GetAnimationInvert(void)
{
	return heroAnimationInvert;
}

// Set Animation Counter of the player
void CPlayerInfo::SetAnimationCounter(int heroAnimationCounter)
{
	this->heroAnimationCounter = heroAnimationCounter;
}
// Get Animation Counter of the player
int CPlayerInfo::GetAnimationCounter(void)
{
	return heroAnimationCounter;
}

// Constrain the position of the Hero to within the border
void CPlayerInfo::ConstrainHero(const int leftBorder, const int rightBorder, 
								  const int topBorder, const int bottomBorder, 
								  float timeDiff,
								  int& mapOffset_x, int& mapOffset_y)
{
	if (hero_x < leftBorder)
	{
		hero_x = leftBorder;
		mapOffset_x =  mapOffset_x - (int) (movementspeed * timeDiff);
		if (mapOffset_x < 0)
			mapOffset_x = 0;
	}
	else if (hero_x > rightBorder)
	{
		hero_x = rightBorder;
		mapOffset_x = mapOffset_x + (int)(movementspeed * timeDiff);
		if (mapOffset_x > 800)	// This must be changed to soft-coded
			mapOffset_x = 800;
	}

	if (hero_y < topBorder)
		hero_y = topBorder;
	else if (hero_y > bottomBorder)
		hero_y = bottomBorder;
}