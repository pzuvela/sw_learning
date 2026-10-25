#include <iostream>
#include <vector>
#include <cassert>
#include <utility>

#include "includes/test_case.h"
#include "includes/test_helpers.h"

using IntVectorTestCase =
TestCase<std::vector<int>, std::vector<int>>;

void moveZeroes(std::vector<int>& nums)
{
    /*
    Given an integer array, move all zeroes to the end while preserving
    the relative order of non - zero elements.
    */

    int write = 0;

    for (int read = 0; read < static_cast<int>(nums.size()); read++)
    {
        if (nums[read] != 0)
        {
            std::swap(nums[write], nums[read]);
            write += 1;
        }
    }
}

void testMoveZeroes()
{
    std::vector<IntVectorTestCase> cases
    {
        { { 0, 1, 0, 3, 12 },{ 1, 3, 12, 0, 0 } },
        { { 0, 0, 1 },{ 1, 0, 0 } },
        { { 1, 2, 3 },{ 1, 2, 3 } },
        { { 0, 0, 0 },{ 0, 0, 0 } },
        { { 1 },{ 1 } },
        { {},{} }
    };

    for (const auto& testCase : cases)
    {
        // Important: make a mutable copy here.
        std::vector<int> nums = testCase.input;

        moveZeroes(nums);

        printVector(nums);
        assert(nums == testCase.expected);
    }

    std::cout << "All tests passed\n";
}

int main()
{
    testMoveZeroes();
}