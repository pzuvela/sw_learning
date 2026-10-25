#include "person.h"

#include <iostream>
#include <string_view>

void basic_pointer_demo()
{
    int x = 42;
    int* p = &x; // &x is the address of x; p stores that address.

    std::cout << "x: " << x << '\n';
    std::cout << "address of x: " << &x << '\n';
    std::cout << "address stored in p: " << p << '\n';
    std::cout << "value reached through p: " << *p << '\n';

    *p = 100; // Dereferencing p accesses the original x, so this changes x.
    std::cout << "x after *p = 100: " << x << '\n';
}

void non_owning_pointer_demo()
{
    Person alice("Alice", 30);
    Person* p = &alice; // Non-owning: alice still controls its own lifetime.

    p->setAge(35);
    p->greet();         // p->greet() is shorthand for (*p).greet().
    alice.greet();      // p and alice refer to the same object; no copy occurred.
}

void manual_ownership_demo()
{
    // A raw pointer does not say whether it owns the object. Here the code treats
    // p as owning, so the programmer must pair new with delete.
    Person* p = new Person("Bob", 40);
    p->greet();

    delete p;
    p = nullptr; // Avoid leaving the old, invalid address in p.

    if (p) {
        p->greet();
    }
}

void memory_leak_demo()
{
    Person* p = new Person("Leak", 1);
    p->greet();

    p = nullptr; // The address is lost, but assigning nullptr does not delete.
}

void dangling_pointer_demo()
{
    Person* p = new Person("Dangling", 2);
    delete p;

    p->greet(); // Undefined behavior: p still contains the deleted address.
}

void null_pointer_demo()
{
    Person* p = nullptr;
    p->greet(); // Undefined behavior: there is no Person at this address.
}

int main(int argc, char* argv[])
{
    // Run unsafe demonstrations separately so one crash does not prevent you
    // from trying the others. These are best run under the debugger.
    if (argc == 2) {
        const std::string_view demo = argv[1];

        if (demo == "leak") {
            memory_leak_demo();
            return 0;
        }
        if (demo == "dangling") {
            dangling_pointer_demo();
            return 0;
        }
        if (demo == "null") {
            null_pointer_demo();
            return 0;
        }

        std::cerr << "Unknown demo. Use: leak, dangling, or null.\n";
        return 1;
    }

    basic_pointer_demo();
    non_owning_pointer_demo();
    manual_ownership_demo();

    std::cout << "Run with leak, dangling, or null to try an unsafe demo.\n";
}
