#include "person.h"
#include <iostream>
#include <utility>

// ::in C++ is broader than just namespaces — it's called the scope resolution operator.

Person::Person(const std::string& name, int age)
    : name_(name), age_(age)
{
    std::cout << "Constructed " << name_ << '\n';
}

// The source must be passed by reference. Passing it by value would require
// another copy before the copy constructor could run.
Person::Person(const Person& other)
    : name_(other.name_), age_(other.age_)
{
    std::cout << "Copied " << other.name_ << '\n';
}

Person& Person::operator=(const Person& other)
{
    std::cout << "Assigned from " << other.name_ << '\n';
    name_ = other.name_;
    age_ = other.age_;
    return *this; // Return the current object by reference to allow chaining.
}

Person::Person(Person&& other)
    : name_(std::move(other.name_)),
      age_(other.age_)  // inexpensive to copy int
{
    std::cout << "Moved Person\n";
}

Person& Person::operator=(Person&& other)
{
    std::cout << "Moved Person by assignment from " << other.name_ << '\n';
    name_ = std::move(other.name_);
    age_ = other.age_;
    return *this; // Return the current object by reference to allow chaining.
}

Person::~Person()
{
    std::cout << "Destroyed " << name_ << '\n';
}

Person& Person::setAge(int age)
{
    age_ = age;
    return *this;
}

Person& Person::setName(const std::string& name)
{
    name_ = name;
    return *this;
}

int Person::getAge() const
{
    return age_;
}

const std::string& Person::getName() const
{
    return name_;
}

void Person::greet() const
{
    std::cout << "Hi, I'm " << name_ << " and I'm " << age_ << '\n';
}
