#include <iostream>
#include "process_engine.h"

ProcessEngine::ProcessEngine(IRobot& robot)
	: robot_(robot)
{
	std::cout << "Instantiated robot\n";
};

void ProcessEngine::run(
	Wafer& wafer,
	const Location& destination
)
{
	if (!ProcessEngine::robot_.isReady())
	{
		robot_.initialize();
	}
	bool success = robot_.moveWafer(wafer, destination);

	if (success)
	{
		wafer.location = destination;
	}
};
