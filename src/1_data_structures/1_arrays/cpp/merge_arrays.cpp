#include <iostream>
#include <vector>
#include <cassert>

#include "includes/test_case.h"
#include "includes/test_helpers.h"

struct MergeInput
{
    std::vector<int> nums1;
    int m;
    std::vector<int> nums2;
    int n;
};

using MergeTestCase =
TestCase<MergeInput, std::vector<int>>;


void mergeSorted(
    std::vector<int>& nums1,
    int m,
    const std::vector<int>& nums2,
    int n)
{
    int i = m - 1;
    int j = n - 1;
    int write = m + n - 1;

    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[write] = nums1[i];
            --i;
            --write;
        }
        else
        {
            nums1[write] = nums2[j];
            --j;
            --write;
        }
    }

    while (j >= 0)
    {
        nums1[write] = nums2[j];
        --j;
        --write;
    }
}

void testMergeSorted()
{
    std::vector<MergeTestCase> cases
    {
        {
            { { 1, 2, 3, 0, 0, 0 }, 3,{ 2, 5, 6 }, 3 },
            { 1, 2, 2, 3, 5, 6 }
        },
        {
            { { 1 }, 1,{}, 0 },
            { 1 }
        },
        {
            { { 0 }, 0,{ 1 }, 1 },
            { 1 }
        },
        {
            { { 2, 0 }, 1,{ 1 }, 1 },
            { 1, 2 }
        }
    };

    for (const auto& testCase : cases)
    {
        std::vector<int> nums1 = testCase.input.nums1;

        mergeSorted(
            nums1,
            testCase.input.m,
            testCase.input.nums2,
            testCase.input.n
        );

        printVector(nums1);
        assert(nums1 == testCase.expected);
    }

    std::cout << "All tests passed\n";
}


int main()
{
    testMergeSorted();
}
