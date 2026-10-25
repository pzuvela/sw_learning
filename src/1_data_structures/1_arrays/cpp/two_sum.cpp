#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
#include <chrono>
#include "includes/test_case.h"
#include "includes/test_helpers.h"

struct TwoSumInput
{
	std::vector<int> nums;
	int target;
};

using TwoSumTestCase = TestCase<TwoSumInput, std::vector<int>>;


std::vector<int> twoSum(const std::vector<int>& nums, int target)
{
    int n = static_cast<int>(nums.size());

    std::unordered_map<int, int> seen;

    for (int i = 0; i < n; i++)
    {   
        int complement = target - nums[i];

        if (seen.contains(complement))
        {
            int previousIndex = seen.at(complement);
            return { previousIndex, i };
        }

        seen[nums[i]] = i;
    }
    return {};
}

std::vector<int> twoSum_Loop(const std::vector<int>& nums, int target)
{
    /*
    Problem: Given an array of integers and a target, return the indices of two distinct elements whose sum equals the target.

    Assume exactly one valid answer exists.

    Example :

        Input :
        nums = [2, 7, 11, 15]
        target = 9

        Output :
        [0, 1]
    */

    int n = static_cast<int>(nums.size());

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (nums[i] + nums[j] == target)
            {
                return { i, j };
            }
        }
    }
    
    return { };
}


void testTwoSum() 
{
    std::vector<TwoSumTestCase> cases
    {
        {
            { { 2, 7, 11, 15 }, 9 },
            { 0, 1 }
        },
        {
            { { 3, 2, 4 }, 6 },
            { 1, 2 }
        }
    };

    for (const auto& testCase : cases)
    {
        std::vector<int> result = twoSum(
            testCase.input.nums,
            testCase.input.target
        );

        printVector(result);

        assert(result == testCase.expected);
    }
}

void comparePerformance()
{
    constexpr int n = 50'000;

    std::vector<int> nums(n);

    // Fill with values that don't accidentally form the target.
    for (int i = 0; i < n; ++i)
    {
        nums[i] = i * 2;
    }

    // Force the valid pair to be at the end.
    nums[n - 2] = 1'000'001;
    nums[n - 1] = 1'000'002;

    int target = 2'000'003;

    auto startLoop = std::chrono::high_resolution_clock::now();

    auto resultLoop = twoSum_Loop(nums, target);

    auto endLoop = std::chrono::high_resolution_clock::now();


    auto startMap = std::chrono::high_resolution_clock::now();

    auto resultMap = twoSum(nums, target);

    auto endMap = std::chrono::high_resolution_clock::now();


    assert(resultLoop == resultMap);


    std::chrono::duration<double, std::milli> loopTime =
        endLoop - startLoop;

    std::chrono::duration<double, std::milli> mapTime =
        endMap - startMap;


    std::cout << "\nPerformance comparison\n";
    std::cout << "Input size: " << n << '\n';

    std::cout << "Nested loops: "
        << loopTime.count()
        << " ms\n";

    std::cout << "Unordered map: "
        << mapTime.count()
        << " ms\n";

    std::cout << "Speedup: "
        << loopTime.count() / mapTime.count()
        << "x\n";
}

int main() 
{
    testTwoSum();
    comparePerformance();
}
