#include <iostream>
#include <vector>
#include <cassert>

#include "includes/test_case.h"
#include "includes/test_helpers.h"

struct RemoveDuplicatesExpected
{
    std::vector<int> nums;
    int k;
};

using RemoveDuplicatesTestCase =
TestCase<std::vector<int>, RemoveDuplicatesExpected>;


int removeDuplicates(std::vector<int>& nums)
{
    /*
    Given a sorted array, remove duplicates in-place.

    Input:
    [1, 1, 2, 2, 3]

    After:
    [1, 2, 3, ...]

    Return:
    3
    */


    if (nums.empty())
    {
        return 0;
    }

    int write = 1;

    for (int read = 1; read < static_cast<int>(nums.size()); ++read)
    {
        if (nums[read] != nums[write - 1])
        {
            nums[write] = nums[read];
            ++write;
        }

    }

    return write;
}


void testRemoveDuplicates()
{
    std::vector<RemoveDuplicatesTestCase> cases
    {
        {
            { 1, 1, 2, 2, 3 },
            { { 1, 2, 3 }, 3 }
        },
        {
            { 1, 1, 1 },
            { { 1 }, 1 }
        },
        {
            { 1, 2, 3 },
            { { 1, 2, 3 }, 3 }
        },
        {
            {},
            { {}, 0 }
        }
    };

    for (const auto& testCase : cases)
    {
        std::vector<int> nums = testCase.input;

        int k = removeDuplicates(nums);

        assert(k == testCase.expected.k);

        for (int i = 0; i < k; ++i)
        {
            assert(nums[i] == testCase.expected.nums[i]);
        }

        std::cout << "k = " << k << '\n';
        printVector(nums);
    }

    std::cout << "All tests passed\n";
}


int main()
{
    testRemoveDuplicates();
}
