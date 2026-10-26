#include <iostream>
#include <memory>
#include <string>


class Person
{
public:
    std::string name;
    std::shared_ptr<Person> friend_;

    Person(const std::string& name)
        : name(name)
    {
        std::cout << "Constructed " << name << '\n';
    }

    ~Person()
    {
        std::cout << "Destroyed " << name << '\n';
    }
};

int main()
{
    auto alice = std::make_shared<Person>("Alice");
    auto bob = std::make_shared<Person>("Bob");

    alice->friend_ = bob;
    bob->friend_ = alice;
}

