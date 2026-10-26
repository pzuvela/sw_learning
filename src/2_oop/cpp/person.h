#pragma once

#include <string>

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
