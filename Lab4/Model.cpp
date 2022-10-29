#include "Model.h"
#include <crtdbg.h>

void CModel::setProbabilities(double _p1, double _p2)
{
	channel1.SetProbability(_p1);
	channel2.SetProbability(_p2);
}

void CModel::simulate(const unsigned int queueLen)
{
	for (size_t i = 0; i < queueLen; ++i)
	{
		UpdateStatisticData();

		order.GetNextState();
		channel1.GetNextState(1);
		channel2.GetNextState(2);

		auto channel2Task = channel2.GetTask();
		if (channel2Task)
			ConfirmTask(channel2Task);

		auto channel1Task = channel1.GetTask();
		if (channel1.IsEmpty() && !order.IsEmpty())
			channel1.AcceptTask(order.GetTask());

		if (channel2.IsEmpty())
			channel2.AcceptTask(channel1Task);
		else
			RejectTask(channel1Task);

		auto generatedTask = source.GenerateTask();

		if (channel1Task)
			Aq++;

		if (channel1.IsEmpty())
			channel1.AcceptTask(generatedTask);
		else
		{
			if (order.IsEmpty())
				order.AcceptTask(generatedTask);
			else
				RejectTask(generatedTask);
		}
	}
	
	if (!order.IsEmpty())
		TasksStatistic.push_back(std::make_pair(order.GetTask(), true));

	if (!channel1.IsEmpty())
		TasksStatistic.push_back(std::make_pair(channel1.ReturnTask(), true));
	
	if (!channel2.IsEmpty())
		TasksStatistic.push_back(std::make_pair(channel2.ReturnTask(), true));
	
	CalculateParams();
}

CModel::CModel()
{
	p1 = 0.4;
	p2 = 0.5;
	
	channel1 = Channel(&randomiser);
	channel2 = Channel(&randomiser);
}

CModel::CModel(double _p1, double _p2) : p1(_p1), p2(_p2)
{
	clear();

	channel1 = Channel(&randomiser);
	channel2 = Channel(&randomiser);
}

void CModel::clear()
{
	StatesStatistic.clear();
	Ticks = 0;
	ServedTasksCount = 0;
	RegectedTasksCount = 0;
	
	for (auto ts : TasksStatistic)
		delete ts.first;
	
	TasksStatistic.clear();

	source.clear();
	order.clear();
	channel1.clear();
	channel2.clear();

	A = 0;
	Q = 0;
	Potk = 0;
	Wc = 0;
	Lc = 0;
	Wq = 0;
	Lq = 0;
}

std::map<QString, unsigned int> CModel::getResult()const
{
	return StatesStatistic;
}

double CModel::getA()
{
	return A;
}

double CModel::getPotk()
{
	return Potk;
}

double CModel::getQ()
{
	return 1 - Potk;
}

double CModel::getLc()
{
	return Lc;
}

double CModel::getWc()
{
	return Wc;
}

double CModel::getLq()
{
	return Lq;
}

double CModel::getWq()
{
	return Wq;
}

double CModel::getAq()
{
	return Aq;
}

unsigned int CModel::getTicks()
{
	return Ticks;
}

void CModel::UpdateStatisticData()
{
	Ticks++;
	
	QString stateSign = QString("P") + QString().number(source.GetState()) + QString().number(order.GetState()) + QString().number(channel1.GetState())
		+ QString().number(channel2.GetState());

	StatesStatistic[stateSign]++;

	// среднее число заявок в системе
	Lc += order.GetState() + channel1.GetState() + channel2.GetState();

	// среднее число заявок в очереди
	Lq += order.GetState();
}

void CModel::CalculateParams()
{
	A = A / Ticks;
	Aq = Aq / Ticks;
	Lc = Lc/Ticks;
	Lq = Lq / Ticks;
	
	int orderTasksCount = 0;
	int notProcessedTasks = 0;
	int K1 = 0;
	int K2 = 0;
	int L1 = 0;
	int L2 = 0;

	for (auto ts : TasksStatistic)
	{
		Wq += ts.first->GetTicksInOrder();
		Wc += ts.first->GetTicks(1) + ts.first->GetTicks(2);

		K1 += ts.first->GetTicks(1);
		K2 += ts.first->GetTicks(2);

		if (ts.first->GetTicksInOrder())
			orderTasksCount++;

		if (!ts.first->GetTicksInOrder() && !ts.first->GetTicks(1) && !ts.first->GetTicks(2))
			notProcessedTasks++;

		if (ts.first->GetTicks(1))
			L1++;
		if (ts.first->GetTicks(2))
			L2++;

		if (!ts.second)
			Potk++;
	}


	if (orderTasksCount)
		Wq = Wq / orderTasksCount;
	else
		Wq = 0;

	Wc = Wq + (L1 ? K1 / L1 : 0) + (L2 ? K2 / L2 : 0);

	Potk = Potk/TasksStatistic.size();
}

void CModel::RejectTask(Task* t)
{
	if (t)
		TasksStatistic.push_back(std::make_pair(t, false));
}

void CModel::ConfirmTask(Task* t)
{
	if (t)
	{
		TasksStatistic.push_back(std::make_pair(t, true));
		A++;
	}
}
