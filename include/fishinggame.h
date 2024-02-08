#pragma once

#include "boot.h"
#include "fish.h"
#include "functions.h"

class FishingGame
{
public:
	FishingGame(int64_t level);
	~FishingGame();

	void castFishingRod(int sector);

private:
	
	struct Sector {
		Fish* pFish = nullptr;
		Boot* pBoot = nullptr;
	};

	Sector m_field[N];

	void fillingField();
	void printInfo(int64_t level) const;
};