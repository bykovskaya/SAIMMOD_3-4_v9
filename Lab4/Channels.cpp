#include "Channels.h"

Task* Source::GenerateTask()
{
	TicksTillNewTask--;

	if (TicksTillNewTask == 0)
	{
		TicksTillNewTask = TICKS;
		return new Task(GeneratedTasksCount++);
	}

	return nullptr;
}

int Source::GetState()
{
	return TicksTillNewTask;
}

void Source::clear()
{
	TicksTillNewTask = TICKS;
	GeneratedTasksCount = 0;
}

Channel::Channel(CRandomiser* r) : randomiser(r) {}

Channel::Channel() {}

void Channel::SetProbability(double p) { P = p; }

bool Channel::IsEmpty()
{
	if (!task)
		return true;

	return false;
}

void Channel::AcceptTask(Task* t)
{
	task = t;
}

Task* Channel::GetTask()
{
	if (IsProcessed())
	{
		auto outTask = task;
		task = nullptr;
		return outTask;
	}

	return nullptr;
}

int Channel::GetState()
{
	if (task) return 1;
	
	return 0;
}

void Channel::GetNextState(int channelNum)
{
	if (task)
		task->IncreaseTick(channelNum);
}

void Channel::clear()
{
	task = nullptr;
	P = 0;
}

Task* Channel::ReturnTask()
{
	return task;
}

bool Channel::IsProcessed()
{
	if (randomiser->GetRand() > P)
		return true;

	return false;
}

bool Order::IsEmpty()
{
	if (!task)
		return true;

	return false;
}


void Order::AcceptTask(Task* t)
{
	task = t;
}

Task* Order::GetTask()
{
	Task* outTask = task;
	task = nullptr;
	return outTask;
}

int Order::GetState()
{
	if (task)
		return 1;

	return 0;
}

void Order::GetNextState(int cN)
{
	if (task)
		task->IncreaseTickInOrder();
}

void Order::clear()
{
	task = nullptr;
}

Task::Task(unsigned int taskNum): TaskNum(taskNum) {}