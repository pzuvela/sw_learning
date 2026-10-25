#include <iostream>
#include <vector>


template <typename T>
void printResult(const std::vector<T>& resultNums)
{

   for (const T& i : resultNums)
   {
       std::cout << i << ' ';
   }

   std::cout << '\n';
}
