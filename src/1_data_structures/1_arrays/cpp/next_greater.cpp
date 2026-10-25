#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
#include "includes/test_case.h"
#include "includes/test_helpers.h"


using IntVectorTestCase = TestCase<std::vector<int>, std::vector<int>>;


std::vector<int> nextGreater(const std::vector<int>& nums) 
{

    int n = static_cast<int>(nums.size());
    std::vector<int> result(n, -1);

    std::stack<int> stack;

    for (int i  = n-1; i >= 0; --i)
    {

      while (!stack.empty() && stack.top() <= nums[i])
      {
           stack.pop();
      }

      if (!stack.empty()) 
      {
           result[i] = stack.top();
      }

      stack.push(nums[i]);

    }

    return result;

}

void testNextGreater() 
{
    std::vector<IntVectorTestCase> cases
    {
        {{2, 1, 4, 3}, {4, 4, -1, -1}},
        {{1, 2, 3}, {2, 3, -1}},
        {{3, 2, 1}, {-1, -1, -1}},
        {{5}, {-1}},
        {{}, {}}
    };

    for (const IntVectorTestCase& testCase : cases)
    {
        std::vector<int> result = nextGreater(testCase.input);
        printResult(result);
        assert(result == testCase.expected);
    }

    std::cout << "All tests passed\n";
}


int main()
{
    testNextGreater();
}

