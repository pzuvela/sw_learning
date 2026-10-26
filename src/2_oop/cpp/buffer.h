#include <iostream>

class Buffer
{
private:
    int* data_;
    int size_;

public:
    Buffer(int size);
    Buffer(const Buffer& other);
    Buffer& operator=(const Buffer& other);
    ~Buffer();
};