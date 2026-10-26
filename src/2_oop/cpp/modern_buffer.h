#pragma once

#include <vector>

class ModernBuffer
{
private:
    std::vector<int> data_;

public:
    ModernBuffer(int size);

    ModernBuffer(const ModernBuffer& other);
    ModernBuffer& operator=(const ModernBuffer& other);

    ModernBuffer(ModernBuffer&& other) noexcept;
    ModernBuffer& operator=(ModernBuffer&& other) noexcept;

    ~ModernBuffer();
};