#pragma once

#include "common.h"
#include "Channels.h"
#include <map>
#include <qstring.h>

class CModel
{
public:
	CModel();
	CModel(double _p1, double _p2);
	~CModel() {};

	void setProbabilities(double _p1, double _p2);
	void simulate(const unsigned int queueLen);
	void clear();
	std::map<QString, unsigned int> getResult()const;

	double getA();
	double getQ();
	double getPotk();
	double getLc();
	double getWc();
	double getLq();
	double getWq();
	double getAq();
	unsigned int getTicks();

private:
	std::map<QString, unsigned int> StatesStatistic;
	std::vector<std::pair<Task*, bool>> TasksStatistic;
	unsigned int Ticks = 0;
	unsigned int ServedTasksCount = 0;
	unsigned int RegectedTasksCount = 0;
	CRandomiser randomiser;

	Source source;
	Order order;
	Channel channel1;
	Channel channel2;

	std::vector<Task*> tasks;

	double A = 0;
	double Q = 0;
	double Potk = 0;
	double Wc = 0;
	double Lc = 0;
	double Wq = 0;
	double Lq = 0;
	double Aq = 0;

	double p1 = 0;
	double p2 = 0;

private:
	void UpdateStatisticData();
	void CalculateParams();
	void RejectTask(Task* t);
	void ConfirmTask(Task* t);
};

//оболочка для рандома вероятностей
