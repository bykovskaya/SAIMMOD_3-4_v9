#include "Randomiser.h"
#include "LemerGenerator.h"

CRandomiser::CRandomiser()
{
	CLemerGenerator generator(5678, 32954, 657745, 100000);
	generator.GetRandom(randomised);
	size = randomised.size();
}

double CRandomiser::GetRand()
{
	unsigned int ind = counter;
	
	if (counter + 1 < size)
		counter++;
	else
		counter = 0;

	return randomised[ind].X;
}

