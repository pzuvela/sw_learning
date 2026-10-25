#include <iostream>
#include <vector>
#include <cassert>

#include "includes/test_case.h"
#include "includes/test_helpers.h"

struct RemoveElementInput
{
    std::vector<int> nums;
    int val;
};

struct RemoveElementExpected
{
    std::vector<int> nums;
    int k;
};

using RemoveElementTestCase = TestCase<RemoveElementInput, RemoveElementExpected>;


int removeElement(std::vector<int>& nums, int val)
{
    int write = 0;

    for (int read = 0; read < static_cast<int>(nums.size()); ++read)
    {

        if (nums[read] != val)
        {
            nums[write] = nums[read];
            ++write;
        }
    }

    return write;
}


void testRemoveElement()
{
    std::vector<RemoveElementTestCase> cases
    {
        {
            { { 3, 2, 2, 3 }, 3 },
            { { 2, 2 }, 2 }
        },
        {
            { { 0, 1, 2, 2, 3, 0, 4, 2 }, 2 },
            { { 0, 1, 3, 0, 4 }, 5 }
        },
        {
            { { 1, 1, 1 }, 1 },
            { {}, 0 }
        },
        {
            { { 1, 2, 3 }, 9 },
            { { 1, 2, 3 }, 3 }
        },
        {
            { {}, 1 },
            { {}, 0 }
        }
    };

    for (const auto& testCase : cases)
    {
        std::vector<int> nums = testCase.input.nums;

        int k = removeElement(
            nums,
            testCase.input.val
        );

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
    testRemoveElement();
}
