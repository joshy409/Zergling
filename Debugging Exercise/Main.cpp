// A Debugging Exercise by Marc Chee (marcc@aie.edu.au)
// 18/12/2016

// Marines are trying to "de-bug" an area (haha . . . haha)
// However something's up with this code . . . figure out what's going wrong
// When you're finished, there should be no compiler errors or warnings
// The encounter should also run and finish correctly as per the rules in the comments

// In many cases there are differences between what's in otherwise identical sections
// for Marines and Zerglings. It's good to be able to tell what the differences are
// and why they might be important.

// What's efficient and inefficient? Why?
// What uses more memory and what doesn't? Why?

// Last modified by Terry Nguyen (terryn@aie.edu.au)
// 10/09/2018

#include <iostream>
#include "Marine.h"
#include "Zergling.h"

using std::cout;
using std::endl;

bool marineAlive(Marine * squadArr, size_t arrSize);
bool zerglingAlive(Zergling * swarmArr, size_t arrSize);

int main()
{
	Marine squad[10];
	int squadSize = 10;

	Zergling swarm[20];
	int swarmSize = 20;

	int aliveMarines = squadSize;
	int aliveZerglings = swarmSize;

	cout << "A squad of marines approaches a swarm of Zerglings and opens fire! The Zerglings charge!" << endl;
	cout << endl;
	// Attack each other until only one team is left alive
	while (marineAlive(squad, squadSize) && zerglingAlive(swarm, swarmSize)) // If anyone is left alive to fight . . .
	{
		if (marineAlive(squad, squadSize)) // if there's at least one marine alive
		{
			for (size_t i = 0; i < squadSize; i++) // go through the squad
			{
				//skips if the marine at index i is dead
				if (!squad[i].isAlive()) {
					continue;
				}

				for (size_t j = 0; j < swarmSize; j++) { //go through the swarm
					//skips if the zergling at index i is dead
					if (!swarm[j].isAlive()) {
						continue;
					}

					// each alive marine will attack the first alive zergling in the swarm
					cout << "A marine " << i << " fires zergling "<< j << " for " << squad[i].attack() << " damage. " << endl;

					swarm[j].takeDamage(squad[i].attack());

					if (!swarm[j].isAlive()) // if the zergling dies or survives, it is marked as such
					{
						aliveZerglings--;
						cout << "The zergling " << j << " dies" << endl;
						break;
					}
					else {
						cout << "Zergling " << j << " survives" << endl;
						break;
					}
				}
			}
			cout << "There are " << aliveZerglings << " zerglings left" << endl;
		}
		cout << endl;
		if (zerglingAlive(swarm, swarmSize)) // if there's at least one zergling alive
		{
			for (size_t i = 0; i < swarmSize; i++) // go through the swarm
			{
				//skips if the zergling at index i is dead
				if (!swarm[i].isAlive()) {
					continue;
				}

				
				for (size_t j = 0; j < squadSize; j++) { //go throught the squad
			        //skips if the marine at index i is dead
					if (!squad[j].isAlive()) {
						continue;
					}
					// each alive zergling will attack the first alive marine in the squad
					cout << "A zergling " << i << " attacks marine " << j << " for " << swarm[i].attack() << " damage. " << endl;

					squad[j].takeDamage(swarm[i].attack());
					if (!squad[j].isAlive()) // if the marine or survives dies, it is marked as such
					{
						aliveMarines--;
						cout << "The marine " << j << " dies" << endl;
						break;
					}
					else {
						cout << "Marine " << j << " survives"  << endl;
						break;
					}
				}
			}
			cout << "There are " << aliveMarines << " marines left" << endl;
		}
		cout << endl;
	}

	// Once one team is completely eliminated, the fight ends and one team wins
	cout << "The fight is over. ";
	if (marineAlive(squad,squadSize))
	{
		cout << "The Marines win." << endl;
	}
	else {
		cout << "The Zerg win." << endl;
	}
}
	


// Is there a Marine Alive?
bool marineAlive(Marine * squadArr, size_t arrSize)
{
	for (size_t i = 0; i < arrSize; i++) {
		//if there is at least 1 marine alive return true;
		if (squadArr[i].isAlive()) {
			return true;
			break;
		}
	}
	return false;
}

// Is there a zergling Alive
bool zerglingAlive(Zergling * swarmArr, size_t arrSize)
{
	for (size_t i = 0; i < arrSize; i++) {
		//if there is at least 1 zergling alive return true;
		if (swarmArr[i].isAlive()) {
			return true;
			break;
		}
	}
	return false;
}
