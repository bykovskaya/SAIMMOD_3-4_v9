#pragma once
#include "common.h"

class CRandomiser
{
public:
	CRandomiser();
	~CRandomiser() {};

	double GetRand();

private:
	std::vector<STRandomData> randomised;
	unsigned int counter = 0;
	unsigned int size;
};

