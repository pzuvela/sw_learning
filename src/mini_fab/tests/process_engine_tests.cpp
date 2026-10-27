#include <gtest/gtest.h>

#include "process_engine.h"
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
	};

	TEST_F(ProcessEngineTest, UpdatesWaferLocationWhenRobotMoveSucceeds)
	{
		MockRobot robot{ true };

		ProcessEngine engine(robot);

		engine.run(
			wafer,
			destination
		);

		EXPECT_EQ(wafer.location, destination);
	}

	TEST_F(ProcessEngineTest, KeepsWaferLocationWhenRobotMoveFails)
	{
		MockRobot robot{ false };

		ProcessEngine engine(robot);

		Location originalLocation = wafer.location;

		engine.run(
			wafer,
			destination
		);

		EXPECT_EQ(wafer.location, originalLocation);
	}
}