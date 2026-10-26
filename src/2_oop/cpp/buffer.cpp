#include <iostream>
#include "buffer.h"

// RAII = Resource Acquisition is Initialization

// RAII =
// acquire resource in / with an object
// ↓
// object owns resource
// ↓
// object leaves scope
// ↓
// destructor releases resource automatically

// Tie a resource's lifetime to an object's lifetime, 
// so cleanup happens automatically when the object goes out of scope.  ( delete, manage in destructor )

// Resources aren't necessarily memory only either. 
// The same idea applies to files, locks, sockets, database handles, etc.


Buffer::Buffer(int size)
    : size_(size)
{
    data_ = new int[size_];

    std::cout << "Allocated "
        << size_ << " integers\n";
};

Buffer::Buffer(const Buffer& other) 
{
    size_ = other.size_;
    data_ = new int[size_];

    for (int i = 0; i < size_; i++ ) 
    {
        data_[i] = other.data_[i];
    }

    std::cout << "Allocated "
        << size_ << " integers by copy\n";
};

Buffer& Buffer::operator=(const Buffer& other)
{
    // Prevent deleting the memory we are about to copy from during self-assignment
    if (this == &other)
    {
        return *this;
    }

    size_ = other.size_;

    delete[] data_;  // Need to first free the memory, because overwriting the pointer only would lead to memory leak...

    data_ = new int[size_];

    for (int i = 0; i < size_; i++)
    {
        data_[i] = other.data_[i];
    }

    std::cout << "Allocated "
        << size_ << " integers by copy assignment\n";

    return *this;
};

Buffer::~Buffer()
{
    delete[] data_; // delete ~ delete single obj, delete[] ~ delete an array of objs - knows it needs to destroy all elements

    // new ↔ delete
    // new[] ↔ delete[]

    std::cout << "Freed buffer\n";
};
