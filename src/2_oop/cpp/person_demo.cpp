#include "person.h"
#include <utility>

Person constructObj() 
{
    Person alice("Alice", 30);
    alice.setAge(31).setName("Alicia"); // Setters return *this for chaining.
    alice.greet();
    return alice;  // NRVO can construct alice directly in the caller's result,
                   // so no copy or move is needed. If NRVO is not performed,
                   // the local object can be moved on return.
}

Person copyObj(Person& alice) 
{
    Person copied(alice); // Copy construction creates a new object.
    copied.greet();
    return copied;
}

Person copyAssignment(Person& alice)
{
    Person assigned("Bob", 40);
    assigned = alice; // Copy assignment updates an existing object.
    assigned.greet();
    return assigned;
}

Person move(Person& alice)
{
    Person moved = std::move(alice);

    alice.greet();
    moved.greet();
    return moved;
}

void moveByAssignment()
{
    Person a("Alice", 30);
    Person b("Bob", 50);

    b = std::move(a);

    b.greet();
    a.greet();
}

int main()
{
    Person alice = constructObj();
    Person copied = copyObj(alice);
    Person assigned = copyAssignment(alice);
    Person moved = move(assigned);
    moveByAssignment();
    // Local objects are destroyed automatically, in reverse construction order.
}
