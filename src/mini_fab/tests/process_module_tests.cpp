#include <gtest/gtest.h>
#include <stdexcept>

#include "sim_process_module.h"
#include "domain/wafer.h"
#include "domain/recipe.h"
#include "domain/location.h"

namespace MiniFab::Tests
{
    // Arrange, Act, Assert -> AAA principle for testing

    TEST(SimProcessModuleTest, IsNotReadyBeforeInitialization)
    {
        SimProcessModule module = SimProcessModule();

        bool isReady = module.isReady();

        EXPECT_FALSE(isReady);
    }

    TEST(SimProcessModuleTest, IsReadyAfterInitialization)
    {
        SimProcessModule module = SimProcessModule();

        module.initialize();

        bool isReady = module.isReady();

        EXPECT_TRUE(isReady);
    }


    TEST(SimProcessModuleTest, ProcessSucceedsWhenInitialized)
    {
        SimProcessModule module = SimProcessModule();

        Wafer wafer{
            .id = 1,
            .location = Location{
                .station = Station::LoadPort,
                .slot = 2
            }
        };

        Recipe recipe{
            .id = 2,
            .name = "Recipe1",
            .durationSeconds = 50.6
        };

        module.initialize();

        bool isSuccessful = module.process(wafer, recipe);

        EXPECT_TRUE(isSuccessful);
    }

    TEST(SimProcessModuleTest, ProcessThrowsWhenNotInitialized)
    {
        SimProcessModule module = SimProcessModule();

        Wafer wafer{
            .id = 1,
            .location = Location{
                .station = Station::LoadPort,
                .slot = 2
            }
        };

        Recipe recipe{
            .id = 2,
            .name = "Recipe1",
            .durationSeconds = 50.6
        };

        EXPECT_THROW(module.process(wafer, recipe), std::logic_error);
    }
}