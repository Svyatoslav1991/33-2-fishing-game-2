#include <iostream>
#include "fishinggame.h"


int main() {
	std::cout << "\tTASK 33.2 FISHING GAME\n\n";

	int64_t level;
	do
	{
		std::cout << "Choose level (1 - 5):\n";
		std::cout << "1 - easy, 2 - adventurous, 3 - heroic, 4 - epic, 5 - Legendary\n";
		level = myCin<int64_t>();
	} while (level < 1 || level > 5);

	try
	{
		FishingGame game(level);
		int64_t sector;
		while (true)
		{
			std::cout << "\nEnter the sector number to cast the fishing rod (0-8)\n";
			sector = myCin<int64_t>();
			game.castFishingRod(sector);

			std::cout << "You didn't catch anything, try again\n";

			attempts++;
		}
	}
	catch (const Fish* pFish)
	{
		std::cout << "Congratulations! You caught a fish in " << attempts << " attempts\n";
	}
	catch (const Boot* pFish)
	{
		std::cout << "Oops! You caught a boot. Game over!\n";
	}
	catch (const std::exception& ex)
	{
		std::cout << "Error: " << ex.what() << "\n";
	}
	catch (...)
	{
		std::cout << "Something went wrong\n";
	}

	return 0;
}