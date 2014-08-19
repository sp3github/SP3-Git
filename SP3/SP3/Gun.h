#pragma once
#include "Define.h"

#ifndef CGUN_H
#define CGUN_H

class CGun
{
private:
	float Damage;
	float AttackSpeed;
	float Ammo;
public:
	CGun();
	~CGun();
	
	float GetDamage();
	void SetDamage(float set);
	
	float GetAttackSpeed();
	void SetAttackSpeed(float set)
};
#endif 