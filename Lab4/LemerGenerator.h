#pragma once
#include <qstring>
#include "common.h"

class CLemerGenerator
{
private:
	unsigned int A, R0, M;
	unsigned int N;

	QString Msg;

public:
	
	CLemerGenerator(unsigned int a, unsigned int r0, unsigned int m, unsigned int n);

	void GetRandom(std::vector<STRandomData>&);
};

