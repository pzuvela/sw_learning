#pragma once

#include <string>

// Five Resource Managemen Functions
// 0. Constructor ; outside the five
// 1. Copy Constructor
// 2. Copy Assignment
// 3. Move Constructor
// 4. Move Assignment
// 5. Destructor

// Rule of Zero vs Rule of Five

// Rule of Five
// If your class needs to manually define one of the five resource-management functions, 
// you should consider whether it needs all five.

// Rule of Zero
// Prefer members that manage their own resources so your class doesn't need to manually 
// implement copy/move/destruction.

class Person
{
private:
    std::string name_;
    int age_;

public:
    Person(const std::string& name, int age); // constructor
    Person(const Person& other); // copy constructor
    Person& operator=(const Person& other); // copy assignment operator
    Person(Person&& other); // rvalue reference for move, move constructor
    Person& operator=(Person&& other); // move assignment operator
    ~Person(); // destructor

    Person& setAge(int age); // setter for age field
    Person& setName(const std::string& name); // setter for name field

    int getAge() const; // getter for age field, const so Person can also be const
    const std::string& getName() const; // getter for name field, const so Person can also be const
    void greet() const;
};
