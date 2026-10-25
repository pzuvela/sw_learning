/*
unique_ptr  -> "this object has one clear owner"
shared_ptr  -> "several things jointly keep this object alive"
raw pointer -> "I can access it, but I don't own it"
*/

#include "person.h"
#include <iostream>
#include <memory>

void sharedOwnership()
{
    std::shared_ptr<Person> p1 = std::make_shared<Person>("Alice", 30); // shared ptr has auto ref count
    std::shared_ptr<Person> p2 = p1;  // copy of shared pointer p1, not underlying obj Alice
    std::cout << "Count: " <<  p1.use_count() << '\n';

    p2->setAge(50);
    p1->greet();
    p2->greet();
}

void sharedOwnership_RefCountChangeWScope()
{
    std::shared_ptr<Person> p1 = std::make_shared<Person>("Alice", 30);
    std::cout << "Count after p1: " << p1.use_count() <<  '\n';

    {
        std::shared_ptr<Person> p2 = p1;
        std::cout << "Count after p2: " << p1.use_count() << '\n';

        p2->setAge(50);

    }

    std::cout << "Count after p2 leaves scope: " << p1.use_count() << '\n';
    p1->greet();
}

void resetSharedPointer()
{
    std::shared_ptr<Person> p1 = std::make_shared<Person>("Alice", 30); // shared ptr has auto ref count
    std::shared_ptr<Person> p2 = p1;  // copy of shared pointer p1, not underlying obj Alice
    std::cout << "Count: " <<  p1.use_count() << '\n';

    p2.reset(); // unlike unique ptr, reset() here does not destroy Alice obj, because p1 still owns the obj.
    std::cout << "Count: " <<  p1.use_count() << '\n';
    p1->greet();
}

void resetSharedPointerEntirely()
{
    std::shared_ptr<Person> p1 = std::make_shared<Person>("Alice", 30); // shared ptr has auto ref count
    std::shared_ptr<Person> p2 = p1;  // copy of shared pointer p1, not underlying obj Alice
    std::cout << "Count: " <<  p1.use_count() << '\n';

    p2.reset(); // unlike unique ptr, reset() here does not destroy Alice obj, because p1 still owns the obj.
    std::cout << "Count: " <<  p1.use_count() << '\n';
    p1->greet();
    p1.reset();
    std::cout << "Count: " <<  p1.use_count() << '\n';
    p1->greet();
}


int main() 
{
    sharedOwnership();
    sharedOwnership_RefCountChangeWScope();
    resetSharedPointer();
    resetSharedPointerEntirely();
}
