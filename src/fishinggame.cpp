#include "fishinggame.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <stdexcept>

FishingGame::FishingGame(int64_t level)
{
	std::srand(std::time(NULL));

    this->fillingField();
    this->printInfo(level);

}

//---------------------------------------------------------------------------------------------------------

FishingGame::~FishingGame()
{
    for (int64_t i = 0; i < N; ++i)
    {
        if (m_field[i].pFish)
        {
            delete m_field[i].pFish;
        }
        else if (m_field[i].pBoot)
        {
            delete m_field[i].pBoot;
        }
    }
}

//---------------------------------------------------------------------------------------------------------

void FishingGame::castFishingRod(int sector)
{
    if (sector < 0 || sector > N - 1)
    {
        throw std::out_of_range("Invalid sector number");
    }

    if (m_field[sector].pFish != nullptr)
    {
        throw m_field[sector].pFish;
    }
    else if (m_field[sector].pBoot != nullptr)
    {
        throw m_field[sector].pBoot;
    }
}

//---------------------------------------------------------------------------------------------------------

void FishingGame::fillingField()
{
    m_field[std::rand() % N].pFish = new Fish;

    int64_t bootSector;
    for (int64_t i = 0; i < 3; ++i)
    {
        do
        {
            bootSector = std::rand() % N;
        } while (m_field[bootSector].pFish != nullptr || m_field[bootSector].pBoot != nullptr);

        m_field[bootSector].pBoot = new Boot;
    }
}

//---------------------------------------------------------------------------------------------------------

void FishingGame::printInfo(int64_t level) const
{
    if (level < 5)
    {
        std::vector<int> subjects(4, -1);


        int64_t countBoots = 1;

        for (int64_t i = 0; i < N; ++i)
        {
            if (m_field[i].pFish)
            {
                subjects[0] = i;
            }
            else if (m_field[i].pBoot)
            {
                subjects[countBoots++] = i;
            }
        }


		switch (level)
		{
		case 1:
		{
			std::cout << "The fish is in sector " << subjects[0] << "\n";
			std::cout << "Boots in sectors " << subjects[1] << ", " << subjects[2] << ", " << subjects[3] << "\n";
		}
		break;
		case 2:
			std::cout << "Boots in sectors " << subjects[1] << ", " << subjects[2] << ", " << subjects[3] << "\n";
			break;
		case 3:
			std::cout << "Boots in sectors " << subjects[1] << ", " << subjects[2] << ", UNKNOWN\n";
			break;
		case 4:
			std::cout << "Boots in sectors " << subjects[1] << ", UNKNOWN, UNKNOWN\n";
			break;
		default:
			break;
		}
    }
}
