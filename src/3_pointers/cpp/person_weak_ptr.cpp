#include <memory>
#include <iostream>


class Person
{
public:
    std::string name;
    std::weak_ptr<Person> friend_;

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
