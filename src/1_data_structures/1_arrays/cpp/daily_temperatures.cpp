#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
#include "includes/test_case.h"
#include "includes/test_helpers.h"

using IntVectorTestCase = TestCase<std::vector<int>, std::vector<int>>;


std::vector<int> dailyTemperatures(const std::vector<int>& temperatures)
{

    int n = static_cast<int>(temperatures.size());
    std::vector<int> result(n, 0);

    std::stack<int> st;

    for (int i  = n-1; i >= 0; --i)
    {
        while (!st.empty() && temperatures[st.top()] <= temperatures[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
             result[i] = st.top() - i;
        }

        st.push(i);
    }

    return result;
}

void testDailyTemperatures()
{
    std::vector<IntVectorTestCase> cases
    {
        {{73, 74, 75, 71, 69, 72, 76, 73}, {1, 1, 4, 2, 1, 1, 0, 0}},
        {{30, 40, 50, 60}, {1, 1, 1, 0}},
        {{30, 60, 90}, {1, 1, 0}},
        {{70, 70, 71}, {2, 1, 0}},
        {{90, 80, 70}, {0, 0, 0}},
        {{}, {}}
    };

    for (const IntVectorTestCase& testCase : cases)
    {
        std::vector<int> result = dailyTemperatures(testCase.input);
        printVector(result);
        assert(result == testCase.expected);
    }

    std::cout << "All tests passed\n";
}


int main() 
{
    testDailyTemperatures();
}

