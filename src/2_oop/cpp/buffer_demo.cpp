#include "buffer.h"

Buffer instantiateBuffer(int size) 
{
    return Buffer(size);
}

Buffer copy(Buffer& a)
{
    Buffer b(a);
    return b;
}

Buffer copyByAssignment(Buffer& a) 
{
    Buffer b = Buffer(0);
    b = a; // C++ automatic copy constructor impl will make a reference of the data_ array ( will copy the pointer instead of a deep copy ), 
    // need custom one because if b.data_ is copied as pointer, so both a.data_ and b.data_ would have same memory address
    // then delete[] will try to delete twice, but after delete of a memory 
    // will already be freed
    return b;
}

Buffer move(Buffer& a) {
    Buffer b = std::move(a);  // move constructor
    return b;
}

Buffer moveByAssignment(Buffer& a)
{
    Buffer b = Buffer(0);
    b = std::move(a);
    return b;
}


int main()
{
    Buffer a = instantiateBuffer(5);
    Buffer b = copy(a);
    Buffer c = copyByAssignment(a);
    Buffer d = instantiateBuffer(10);
    a = copyByAssignment(b);
    a = a;  // does nothing, short circuited...
    
    a = instantiateBuffer(5);
    Buffer e = move(a);
    Buffer f = moveByAssignment(e);
    e = std::move(e);
    f = std::move(f);
}
