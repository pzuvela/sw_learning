#include <iostream>
#include "process_engine.h"
#include "iprocess_module.h"

ProcessEngine::ProcessEngine(IRobot& robot, IProcessModule& processModule)
	: robot_(robot), processModule_(processModule)
{
	std::cout << "Instantiated robot & process module\n";
}

void ProcessEngine::run(
	Wafer& wafer,
	const Location& destination
)
{
	if (!robot_.isReady())
	{
		robot_.initialize();
	}
	bool success = robot_.moveWafer(wafer, destination);

	if (success)
	{
		wafer.location = destination;
	}
}

bool ProcessEngine::process(
	const Wafer& wafer,
	const Recipe& recipe
) 
{
	if (!processModule_.isReady())
	{
		processModule_.initialize();
	}
	return processModule_.process(wafer, recipe);
}
