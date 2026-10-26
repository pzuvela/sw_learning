#include "buffer.h"

int main()
{
    Buffer a(5);
    Buffer b = a; // C++ automatic copy constructor impl will make a reference of the data_ array ( will copy the pointer instead of a deep copy ), 
                  // need custom one because if b.data_ is copied as pointer, so both a.data_ and b.data_ would have same memory address
                  // then delete[] will try to delete twice, but after delete of a memory 
                  // will already be freed

    Buffer c(10);

    a = c;

    a = a;
}
