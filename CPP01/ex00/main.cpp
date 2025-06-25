#include "Zombie.hpp"

int main(void)
{
	Zombie* zpHeapZombie = newZombie("HeapOne");
	zpHeapZombie->announce();
	delete zpHeapZombie;

	randomChump("Stacky");

	return 0;
}
