#pragma once
#include <vector>
#include <stdio.h>
#include "Entity.h"

class DM2231_Model
{
public:
	DM2231_Model(void);
	~DM2231_Model(void);
	// Update the model
	void Update(void);
	std::vector<CEntity> theArrayOfEntities;
};
