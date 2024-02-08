Task 2. Fishing game

What should be done
Implement a simple fishing simulation game.
The playing field consists of nine sectors of a conditional pond.
At the beginning of the game, a fish appears in one of these sectors using a random number generator.
In the same way, three boots are randomly distributed among the sectors of the pond.
In this case, a boot and a fish cannot be in the same sector at the same time, just like several boots at once in one of the sectors.

The player throws a fishing rod with bait into one of the sectors, the number of which is entered in the standard way through the console.
The player's task is to guess the sector in which the fish is located and, thus, catch it.
If the player lands on an empty sector, then the fishing rod must be cast again.
If the player catches the boot, the game ends with a negative result.

The task must be implemented using exceptions: when a successful cast of a fishing rod generates a special user exception, after which the program should end and notify the user about successful fishing and the number of attempts it took him to do this.
If a boot was caught, a message indicating that the catch was unsuccessful should be displayed.

Recommendations
Remember that you can throw an arbitrary data type as an exception.
It could be a boot or a fish.
In the main function you will need to place the fish randomly.
To do this, do std::srand(std::time(nullptr)); and then the location itself: field[std::rand() % 9].fish = new Fish();
Thanks to the % operator, you will not go beyond the bounds of the array.
