#include <iostream>
#include <vector>


template <typename T>
void printVector(const std::vector<T>& values)
{

   for (const T& value : values)
   {
       std::cout << i << ' ';
   }

   std::cout << '\n';
}
