#include "modern_buffer.h"

int main()
{
    ModernBuffer a(5);

    ModernBuffer b = a;            // copy constructor
    ModernBuffer c(10);
    c = a;                         // copy assignment

    ModernBuffer d = std::move(a); // move constructor
    b = std::move(d);              // move assignment
}
