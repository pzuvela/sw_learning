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
    Buffer(Buffer&& other) noexcept; // "I guarantee this function won't let an exception escape."
                                     // noexcept on a move operation tells C++ containers: "This move is safe; you can rely on it."
    Buffer& operator=(Buffer&& other) noexcept;
    ~Buffer();
};