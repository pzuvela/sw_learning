#include <iostream>
#include <vector>
#include <stack>

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


void printResult(const std::vector<int>& resultNums)
{

   for (int i : resultNums)
   {
       std::cout << i << ' ';
   }

   std::cout << '\n';
}

struct TestCase 
{
    std:vector<int> input;
    std:vector<int> expected;
}


void testNextGreater() 
{
    std::vector<TestCase> cases
    {
        {{2, 1, 4, 3}, {4, 4, -1, -1}},
        {{1, 2, 3}, {2, 3, -1}}
    };

    for (const TestCase& case : cases)
    {
        std::vector<int> result = nextGreater(case.input);
        printResult(result);
        assert(result == case.expected);
    }
}


int main()
{
    testNextGreater();
}

