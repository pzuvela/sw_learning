#include <iostream>
#include <vector>



void printResult(const std::vector<int>& resultNums)
{

   for (int i : resultNums)
   {
       std::cout << i << ' ';
   }

   std::cout << '\n';
}
