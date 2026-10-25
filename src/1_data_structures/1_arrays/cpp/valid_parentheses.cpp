#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include "includes/test_case.h"

using StringBoolTestCase = TestCase<std::string, bool>;

bool validParentheses(const std::string& s)
{

    int n = static_cast<int>(s.size());

    std::vector<char> stack;
    stack.reserve(n);

    std::unordered_set<char> openings{ '(', '[', '{' };
    std::unordered_set<char> closings{ ')', ']', '}' };

    std::unordered_map<char, char> matches{
        { ')', '(' },
        { ']', '[' },
        { '}', '{' }
    };


    for (char c : s)
    {
        if (openings.contains(c)) 
        {
            stack.push_back(c);
        }
        if (closings.contains(c))
        {
            if (stack.empty())
            {
                return false;
            }
            else
            {
                char top = stack.back();

                stack.pop_back();

                if (matches[c] != top)
                {
                    return false;
                }
            }
        }
    }

    return stack.empty();
}


void testValidParentheses()
{
    std::vector<StringBoolTestCase> cases
    {
        {"()[]{}", true },
        { "([{}])", true },
        { "(]", false },
        { "([)]", false },
        { "(((", false },
        { "", true }
    };

    for (const auto& testCase : cases)
    {
        bool result = validParentheses(testCase.input);
        std::cout << testCase.input << ' '  << result << '\n';
        assert(result == testCase.expected);
    }

    std::cout << "All tests passed\n";
}


int main()
{
    testValidParentheses();
}
