#include "irobot.h"
#include "iprocess_module.h"


class ProcessEngine
{
private:
    IRobot& robot_;
    IProcessModule& processModule_;

public:
    ProcessEngine(
        IRobot& robot,
        IProcessModule& processModule
    );

    void run(
        Wafer& wafer,
        const Location& destination
    );

    bool process(
        const Wafer& wafer,
        const Recipe& recipe
    );
};
