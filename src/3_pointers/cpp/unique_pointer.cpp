#include "person.h"
#include <memory>
#include <iostream>


// RAII : Resource Acquisition Is Initialization.
// Tie a resource’s lifetime to a C++ object’s lifetime, 
// so cleanup happens automatically when that object goes out of scope.

// RAII = put cleanup inside a destructor, then let scope manage cleanup for you.

void createUniquePtr()
{
    std::unique_ptr<Person> p = std::make_unique<Person>("Alice", 30); // unique_ptr itself is a normal C++ object. When its lifetime ends, its destructor runs, and its destructor deletes the Person it owns.

    // std::unique_ptr<Person> p2 = p; // ERROR: cannot copy ownership  ; will not build

    p->greet();

    p->setAge(35);
    p->greet();

    // no delete; p goes out of scope -> Person automatically destroyed
    
    Person copy = *p;   // copy constructor called
    Person& ref = *p;   // no copy; ref is an alias/reference to the same Person

    ref.setAge(50);

    copy.setAge(99);

    p->greet();
    copy.greet();
}

void moveOwnership() 
{
    std::unique_ptr<Person> p1 = std::make_unique<Person>("Alice", 30); // unique_ptr itself is a normal C++ object. When its lifetime ends, its destructor runs, and its destructor deletes the Person it owns.
    std::unique_ptr<Person> p2 = std::move(p1);  // p1 becomes nullptr, p2 owns alice obj; is not calling your Person copy constructor. It moves the pointer ownership, not the Person object itself; does not move/copy Alice’s fields. It transfers who owns the existing Alice object.

    // copy  -> duplicate, leaves the original behind; copies fields
    // move->transfer, leaves a nullptr behind; transfers ownership

    // With unique_ptr, copying is forbidden, but moving is allowed because ownership is 
    // transferred rather than duplicated.

    if (!p1)
    {
        std::cout << "p1 owns nothing\n";
    }

    if (p2)
    {
        p2->greet();

        p2->setAge(35);
        p2->greet();
    }
}

void printPerson(Person* p)
{
    if (p)
        p->greet();
}

void getRawPointer()
{
    // owner        -> owns the Person
    // owner.get() -> returns a non-owning raw pointer to that Person;
    // useful for APIs/libraries that expect T*

    std::unique_ptr<Person> owner = std::make_unique<Person>("Alice", 30);

    Person* p = owner.get();
    // delete p; -- do not delete a raw pointer obtained using get(),
    // because owner still owns that object and will delete it later
    // So.get() is for non - owning access only.
    
    printPerson(p);
}

void resetObject()
{
    std::unique_ptr<Person> p = std::make_unique<Person>("Alice", 30);

    p->greet();

    p.reset();  // destroys the obj, makes p empty, holds a nullptr

    if (!p)
        std::cout << "p is empty\n";
}

void releaseUniquePtr()
{
    std::unique_ptr<Person> p = std::make_unique<Person>("Alice", 30);

    Person* raw = p.release(); // releases unique ptr p, making it empty, holds a nullptr, does not own anything anymore, "assigns" the memory address the unique ptr was holding to a raw ptr "raw"

    if (!p)
        std::cout << "p no longer owns anything\n";

    raw->greet();

    delete raw; // raw has to be deleted
    raw = nullptr;
}

// get()->borrow raw pointer, ownership unchanged
// reset()    -> delete owned object
// release()->stop owning, hand raw pointer out

int main() 
{
    createUniquePtr();
    moveOwnership();
    getRawPointer();
    resetObject();
    releaseUniquePtr();
}
