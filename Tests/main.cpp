#include "DiceRoll.h"
#include <iostream>

int main()
{
	//#TODO get rid of this crap, build a compile time random
	//#TODO make better tests, this is simple for demo one
	srand(static_cast<unsigned>(time(nullptr)));

	const D4 d4;
	const D6 d6;
	const D8 d8;
	const D10 d10;
	const D12 d12;
	const D20 d20;
	const D100 d100;

	std::cout << "D4\t" << d4.roll() << std::endl;
	std::cout << "D6\t" << d6.roll() << std::endl;
	std::cout << "D8\t" << d8.roll() << std::endl;
	std::cout << "D10\t" << d10.roll() << std::endl;
	std::cout << "D12\t" << d12.roll() << std::endl;
	std::cout << "D20\t" << d20.roll() << std::endl;
	std::cout << "D100\t" << d100.roll() << std::endl;

	// Exploding die, you have a target number that if you roll, you can roll again

	//if you roll a 6 you "explode"
	const ExplodingRoll<6> d6e;

	uint8_t count = 30;

	while(count != 0)
	{
		std::cout << "D6E\t" << d6e.roll() << std::endl;
		count--;
	}

	// Advantage, roll 2 die, take the highest
	// NOTE: FlatRoll<6> is the same as D6 from the example above

	const Advantage<FlatRoll<6>> d6kh;

	std::cout << "D6KH\t" << d6kh.roll() << std::endl;

	// Disadvantage is like advantage, roll 2 die keep lowest

	const Disadvantage<FlatRoll<6>> d6kl;

	std::cout << "D6KL\t" << d6kl.roll() << std::endl;

	// we can combine a series of differnet dice

	const Roll<FlatRoll<4>, FlatRoll<6>, FlatRoll<8>> d4d6d8;

	std::cout << "D4D6D8\t" << d4d6d8.roll() << std::endl;

	// we can get funky
	// roll 2 die, keep highest, explode on a 6
	// if we don't roll a 6, the highest number we can get is 5. if we roll a 6 the minimum number we can get is 7
	// that would mean on 2 rolls we rolled 5 and less or in 4 rolls we hit 6 and one twice on the explode

	const Roll<Advantage<ExplodingRoll<6>>> d6ekh;

	std::cout << "D6EKH\t" << d6ekh.roll() << std::endl;

}
