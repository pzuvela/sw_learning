/*
Find the second largest distinct element

Given an array of integers, return its second largest distinct element.

Input: [10, 5, 20, 8, 20]
Output : 10

Requirements : Solve in O(n) time and O(1) auxiliary space.Return None if there is no second largest distinct element.
*/

#include <iostream>
#include <vector>
#include <optional>
#include <cassert>
#include "includes/test_case.h"
#include "includes/test_helpers.h"

using SecondLargestTestCase = TestCase<std::vector<int>, std::optional<int>>;

std::optional<int> secondLargest(const std::vector<int>& nums)
{
    int n = static_cast<int>(nums.size());

    if (n < 2)
        return std::nullopt;

    std::optional<int> largest = std::nullopt;
    std::optional<int> secondLargest = std::nullopt;

    for (int num : nums) 
    {
        if (!largest || num > *largest)
        {
            secondLargest = largest;
            largest = num;
        }
        else if (num < *largest && (!secondLargest || num > *secondLargest))
        {
            secondLargest = num;
        }
    }
    return secondLargest;
}


void testSecondLargest()
{
    std::vector<SecondLargestTestCase> cases
    {
        { { 10, 5, 20, 8, 20 }, 10 },
        { { 1, 2 }, 1 },
        { { 5, 5, 5 }, std::nullopt },
        { { 7 }, std::nullopt },
        { {}, std::nullopt },
        { { -5, -10, -3 }, -5 },
        { { 5, 5 }, std::nullopt}
    };

    for (const auto& testCase : cases)
    {
        std::optional<int> result = secondLargest(
            testCase.input
        );

        if (result)
        {
            std::cout << *result << '\n';
        }
        else
        {
            std::cout << "None\n";
        }

        assert(result == testCase.expected);
    }
}

int main()
{
    testSecondLargest();
}

