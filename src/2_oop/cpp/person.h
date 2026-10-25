#pragma once

#include <string>

class Person
{
private:
    std::string name_;
    int age_;

public:
    Person(const std::string& name, int age);
    Person(const Person& other);
    Person& operator=(const Person& other);
    ~Person();

    Person& setAge(int age);
    Person& setName(const std::string& name);

    int getAge() const;
    const std::string& getName() const;
    void greet() const;
};
