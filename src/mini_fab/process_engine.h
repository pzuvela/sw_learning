#include "irobot.h"


class ProcessEngine
{
private:
    IRobot& robot_;

public:
    ProcessEngine(IRobot& robot);

    void run(
        Wafer& wafer,
        const Location& destination
    );
};
