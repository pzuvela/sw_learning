#include <iostream>
#include <utility>
#include "modern_buffer.h"

// None of the Rule of Five functions need to be implemented manually because
// std::vector handles resource management. They are implemented here only for logging.

/*
Old Buffer
──────────
int* data_
    ↓
WE own the memory
    ↓
Need destructor
Need deep-copy constructor
Need copy assignment
Need move constructor
Need move assignment
Need to think about double delete
Need to think about moved-from state
Need to think about self-assignment
    ↓
Rule of Five


ModernBuffer
────────────
std::vector<int> data_
    ↓
VECTOR owns the memory
    ↓
Compiler-generated copy works
Compiler-generated move works
Compiler-generated destruction works
    ↓
Rule of Zero
*/

ModernBuffer::ModernBuffer(int size)
    : data_(size) // No need to pass data_(std::vector<int>(size)); construct data_ directly with size
{
    std::cout << "Constructed " << data_.size() << " integers\n";
}

ModernBuffer::ModernBuffer(const ModernBuffer& other)
    : data_(other.data_)
{
    std::cout << "Copy constructed " << data_.size() << " integers\n";
}

ModernBuffer& ModernBuffer::operator=(const ModernBuffer& other)
{
    data_ = other.data_;

    std::cout << "Copy assigned " << data_.size() << " integers\n";

    return *this;
}

ModernBuffer::ModernBuffer(ModernBuffer&& other) noexcept
    : data_(std::move(other.data_))
{
    std::cout << "Move constructed " << data_.size() << " integers\n";
}

ModernBuffer& ModernBuffer::operator=(ModernBuffer&& other) noexcept
{
    data_ = std::move(other.data_);

    std::cout << "Move assigned " << data_.size() << " integers\n";

    return *this;
}

ModernBuffer::~ModernBuffer()
{
    std::cout << "Destroyed ModernBuffer\n";
}