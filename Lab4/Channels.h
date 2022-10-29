#pragma once

#include "Randomiser.h"
#include <string>
#include <map>

class Task;

#define TICKS 2	
class Source
{
public:
	Source(): TicksTillNewTask(TICKS) {}

	Task* GenerateTask();
	int GetState();
	void clear();

private:
	unsigned int TicksTillNewTask;
	unsigned int GeneratedTasksCount = 0;
};

class BaseChannel
{
public:
	virtual int GetState() = 0;
	virtual Task* GetTask() { return nullptr; }
	virtual void AcceptTask(Task* t) {}
	virtual void GetNextState(int cN = 0) {}
	virtual void clear() {};
};

class Channel: public BaseChannel
{
public:
	Channel();
	Channel(CRandomiser* r);

	bool IsEmpty();
	void SetProbability(double p);

	void AcceptTask(Task* t) override;
	Task* GetTask() override;
	int GetState() override;
	void GetNextState(int cN = 0) override;
	void clear();

	Task* ReturnTask();

private:
	CRandomiser* randomiser;
	Task* task = nullptr;
	double P = 0;
	bool IsProcessed();
};


class Order : public BaseChannel
{
public:
	Order() {};

	bool IsEmpty();

	void AcceptTask(Task* t) override;
	Task* GetTask() override;
	int GetState() override;
	void GetNextState(int cN = 0) override;
	void clear();

private:
	Task* task = nullptr;
};

class Task
{
public:
	Task(unsigned int tNum);

	void IncreaseTick(int channelNum) { TicksCount[channelNum]++; }
	void IncreaseTickInOrder() { TicksInOrder++; }
	int GetTicks(int channelNum) { return TicksCount[channelNum]; }
	int GetTicksInOrder() { return TicksInOrder; }

private:
	unsigned int TaskNum = 0;
	std::map<int, int> TicksCount;
	int TicksInOrder = 0;
};
