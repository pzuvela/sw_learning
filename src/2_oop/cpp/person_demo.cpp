#include "person.h"
#include <utility>

int main()
{
    Person alice("Alice", 30);
    alice.setAge(31).setName("Alicia"); // Setters return *this for chaining.
    alice.greet();

    Person copied(alice); // Copy construction creates a new object.
    copied.greet();

    Person assigned("Bob", 40);
    assigned = alice; // Copy assignment updates an existing object.
    assigned.greet();

    // Local objects are destroyed automatically, in reverse construction order.

    Person moved = std::move(assigned);

    assigned.greet();
    moved.greet();

}
