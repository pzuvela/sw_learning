#include <gtest/gtest.h>

#include "process_engine.h"
#include "sim_process_module.h"
#include "mock_robot.h"
#include "domain/wafer.h"
#include "domain/location.h"

namespace MiniFab::Tests
{

	class ProcessEngineTest : public ::testing::Test
	{
	protected:
		Wafer wafer{
			.id = 1,
			.location = Location{
				.station = Station::LoadPort,
				.slot = 2
			}
		};

		Location destination{
			.station = Station::Aligner,
			.slot = 7
		};

		SimProcessModule processModule;
	};

	TEST_F(ProcessEngineTest, UpdatesWaferLocationWhenRobotMoveSucceeds)
	{
		MockRobot robot{ true };

		ProcessEngine engine(robot, processModule);

		engine.run(
			wafer,
			destination
		);

		EXPECT_EQ(wafer.location, destination);
	}

	TEST_F(ProcessEngineTest, KeepsWaferLocationWhenRobotMoveFails)
	{
		MockRobot robot{ false };

		ProcessEngine engine(robot, processModule);

		Location originalLocation = wafer.location;

		engine.run(
			wafer,
			destination
		);

		EXPECT_EQ(wafer.location, originalLocation);
	}
}