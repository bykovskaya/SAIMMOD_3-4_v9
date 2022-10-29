#include "LemerGenerator.h"

CLemerGenerator::CLemerGenerator(unsigned int a, unsigned int r0, unsigned int m, unsigned int n)
	: A(a), R0(r0), M(m), N(n)
{
}

void CLemerGenerator::GetRandom(std::vector<STRandomData> &vRandom)
{

	for (int i = 0; i < N; i++)
	{
		unsigned int R = (A * R0) % M;
		double x = (double)R / M;
		vRandom.push_back({R0, x});

		R0 = R;
	}
}
