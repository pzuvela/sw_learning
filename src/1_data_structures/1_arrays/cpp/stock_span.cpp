#include <iostream>
#include <vector>
#include <cassert>
#include "includes/test_case.h"
#include "includes/test_helpers.h"


using IntVectorTestCase = TestCase<std::vector<int>, std::vector<int>>;


std::vector<int> stockSpan(const std::vector<int>& prices)
{

    int n = static_cast<int>(prices.size());

	std::vector<int> result(n, 1);

    std::vector<int> stack;
    stack.reserve(n);

    for (int i = 0; i < n; i++) 
    {
        while (!stack.empty() && prices[stack.back()] <= prices[i])
        {
            stack.pop_back();
        }

        if (stack.empty()) 
        {
            result[i] = i + 1;
        }
        else
        {
            result[i] = i - stack.back();
        }

        stack.push_back(i);

    }

    return result;
}

void testStockSpan()
{
    std::vector<IntVectorTestCase> cases
    {
        {{100, 80, 60, 70, 60, 75, 85}, {1, 1, 1, 2, 1, 4, 6}},
        {{10, 20, 30}, {1, 2, 3}},
        {{30, 20, 10}, {1, 1, 1}},
        {{20, 20, 20}, {1, 2, 3}},
        {{50}, {1}},
        {{}, {}}
    };

    for (const auto& testCase : cases)
    {
        std::vector<int> result = stockSpan(testCase.input);

        printVector(result);

        assert(result == testCase.expected);
    }

    std::cout << "All tests passed\n";
}


int main() 
{
    testStockSpan();
}
