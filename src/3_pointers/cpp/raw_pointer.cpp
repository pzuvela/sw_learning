#include <iostream>

int main()
{
    int x = 42;

    int* p = &x;  // int* p means p is a pointer to an int. &x means “address of x”.

    std::cout << "x: " << x << '\n';
    std::cout << "&x: " << &x << '\n';
    std::cout << "p: " << p << '\n';
    std::cout << "*p: " << *p << '\n';  // *p means “access the object/value stored at the address in p” - we can also modify the value, not only read. dereference p ( get the value )

    *p = 100;  // changes x because p points directly at x. p is pointer to x, stores the address of x, *p gets the value - the actual object... can be used on both left and right side of expression ( dereferences; Dereference means: take a pointer and access the actual value/object stored at the address it points to. )
    std::cout << "x: " << x << '\n';

    int y = x;

    y = 500; // does not change x, because x was copied into y

    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}
