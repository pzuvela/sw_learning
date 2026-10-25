#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
#include <chrono>
#include <random>
#include "includes/test_case.h"
#include "includes/test_helpers.h"


using IntVectorTestCase = TestCase<std::vector<int>, std::vector<int>>;


std::vector<int> nextGreater_Loop(const std::vector<int>& nums)
{
    int n = static_cast<int>(nums.size());

	std::vector<int> result(n, -1);

    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (nums[i] < nums[j])
            {
				result[i] = nums[j];
                break;
            }
        }
    }

    return result;
}


std::vector<int> nextGreater_Stack(const std::vector<int>& nums) 
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

std::vector<int> nextGreater(const std::vector<int>& nums)
{
    int n = static_cast<int>(nums.size());
    std::vector<int> result(n, -1);

    std::vector<int> stack;
    stack.reserve(n);

    for (int i = n - 1; i >= 0; --i)
    {
        while (!stack.empty() && stack.back() <= nums[i])
        {
            stack.pop_back();
        }

        if (!stack.empty())
        {
            result[i] = stack.back();
        }

        stack.push_back(nums[i]);
    }

    return result;
}

void testNextGreater()
{
    std::vector<IntVectorTestCase> cases
    {
        { { 2, 1, 4, 3 },{ 4, 4, -1, -1 } },
        { { 1, 2, 3 },{ 2, 3, -1 } },
        { { 3, 2, 1 },{ -1, -1, -1 } },
        { { 5 },{ -1 } },
        { {},{} }
    };

    for (const auto& testCase : cases)
    {
        std::vector<int> resultLoop = nextGreater_Loop(testCase.input);
        std::vector<int> resultStack = nextGreater_Stack(testCase.input);
        std::vector<int> resultVectorStack = nextGreater(testCase.input);

		printVector(resultLoop);
        printVector(resultStack);
        printVector(resultVectorStack);

        assert(resultLoop == testCase.expected);
        assert(resultStack == testCase.expected);
        assert(resultVectorStack == testCase.expected);

        assert(resultLoop == resultStack);
        assert(resultLoop == resultVectorStack);
    }

    std::cout << "All tests passed\n";
}


void comparePerformance()
{
    constexpr int n = 100000;

    std::vector<int> nums(n);

    // Descending input:
    // n, n-1, n-2, ..., 1
    for (int i = 0; i < n; ++i)
    {
        nums[i] = n - i;
    }

    auto startLoop = std::chrono::high_resolution_clock::now();

    auto resultLoop = nextGreater_Loop(nums);

    auto endLoop = std::chrono::high_resolution_clock::now();


    auto startStdStack = std::chrono::high_resolution_clock::now();

    auto resultStdStack = nextGreater_Stack(nums);

    auto endStdStack = std::chrono::high_resolution_clock::now();


    auto startVectorStack = std::chrono::high_resolution_clock::now();

    auto resultVectorStack = nextGreater(nums);

    auto endVectorStack = std::chrono::high_resolution_clock::now();


    assert(resultLoop == resultStdStack);
    assert(resultLoop == resultVectorStack);


    std::chrono::duration<double, std::milli> loopTime =
        endLoop - startLoop;

    std::chrono::duration<double, std::milli> stdStackTime =
        endStdStack - startStdStack;

    std::chrono::duration<double, std::milli> vectorStackTime =
        endVectorStack - startVectorStack;


    std::cout << "\nPerformance comparison\n";
    std::cout << "Input size: " << n << '\n';

    std::cout << "Nested loops: "
        << loopTime.count()
        << " ms\n";

    std::cout << "std::stack: "
        << stdStackTime.count()
        << " ms\n";

    std::cout << "vector as stack: "
        << vectorStackTime.count()
        << " ms\n";

    std::cout << "\nSpeedup vs nested loops\n";

    std::cout << "std::stack: "
        << loopTime.count() / stdStackTime.count()
        << "x\n";

    std::cout << "vector stack: "
        << loopTime.count() / vectorStackTime.count()
        << "x\n";
}


int main()
{
    testNextGreater();
    comparePerformance();
}