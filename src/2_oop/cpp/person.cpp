#include <iostream>
#include <string>


class Person
{

private:
    std::string name_;
    int age_;

public:
    // Constructor
    Person(const std::string& name, int age)
        : name_(name), age_(age)
    {
        std::cout << "Constructed " << name_ << '\n';
    }

    // Copy Constructor, called on copy ( e.g., Person a; Person b(a); )
    Person(const Person& other)  // Must pass by reference, or would encounter recursive loop where the constructor would be copied over and over again
        : name_(other.name_), age_(other.age_)
    {
        std::cout << "Copied " << other.name_ << '\n';
    }


    // Copy Assignment, called on assignment 
    Person& operator=(const Person& other)
    {
        std::cout << "Assigned from " << other.name_ << '\n';

        name_ = other.name_;
        age_ = other.age_;

        return *this; // for method chaining
    }

    // Destructor
    ~Person()
    {
        std::cout << "Destroyed " << name_ << '\n';
    }

    Person& setAge(int age) // if no method chaining, then can return void
    {
        age_ = age;
        return *this; // for method chaining
    }

    int getAge() const // const makes the method "read-only" so can be called on a const instance of Person
    {
        return age_;
    }

    const std::string& getName() const // const makes the method "read-only" so can be called on a const instance of Person
    {
        return name_;
    }

    Person& setName(const std::string& name)   // if no method chaining, then can return void
    { 
        name_ = name;
        return *this; // for method chaining
    }

    void greet() const
    {
        std::cout
            << "Hi, I'm "
            << name_
            << " and I'm "
            << age_
            << '\n';
    }
};


void tests1()
{
    Person a("Alice", 30);

    a.setAge(31)
        .setName("Alicia2");

    a.greet();

    Person b(a);  // Or Person b = a; Two types of copy, copy by construction & copy by assignment, copy construction cannot be done for already instantiated objs

    b.greet();

    Person c("Bob", 40);

    c = a;  // Copy by assignment, reassignment can happen for alr instantiated objs
    c.greet();

    Person d = a;  // copy construction
    d.greet();

    /*
    Pointers to objects become useful when you need one of a few things:
        non-owning access,
        dynamic lifetime,
        polymorphism, or
        data structures that link objects together ( like linked lists ).
    */

    /*
    Normal local object     -> Person p;
    Need an alias/reference -> Person& or Person*
    Need owned dynamic obj  -> unique_ptr<Person>
    Need shared ownership   -> shared_ptr<Person>
    */

    /*
    nullptr is useful to check whether pointer points to nothing or not...

    p = &x       -> points to x
    *p           -> access x through p
    p = nullptr  -> points to nothing
    */

}

void tests2()
{
    Person a("Alice", 30);

    Person* p = &a;   // non-owning pointer, a still destroyed whne goes out of scope... vs Person* p = new Person(...);

    p->greet();

    p->setAge(35);
    p->setName("Alicia");

    p->greet();

    a.greet();
}

void tests3()
{
    Person* p = new Person("Alice", 30);  // dynamically allocated object; we are responsible for delete, we are treating p as the owning handle of the obj, but C++ does not know that... raw pointers are thereby dangerous!

    p->greet();

    p->setAge(35);
    p->greet();

    delete p;

    p = nullptr;  // good habit, or p would still contain the address to the obj... dangling pointer!
}

void tests4()
{
    Person* p = new Person("Alice", 30);  // dynamically allocated object; we are responsible for delete, we are treating p as the owning handle of the obj, but C++ does not know that... raw pointers are thereby dangerous!

    p->greet();

    p->setAge(35);
    p->greet();

    // delete p;   // intentionally omitted -> memory leak

    p = nullptr;   // loses the address; leaked object still exists
}

void tests5()
{
    Person* p = new Person("Alice", 30);  // dynamically allocated object; we are responsible for delete, we are treating p as the owning handle of the obj, but C++ does not know that... raw pointers are thereby dangerous!

    p->greet();

    p->setAge(35);

    delete p;

    p->greet();  //   dangling pointer, undefined behavior
}

void tests6()
{
    Person* p = new Person("Alice", 30);  // dynamically allocated object; we are responsible for delete, we are treating p as the owning handle of the obj, but C++ does not know that... raw pointers are thereby dangerous!

    p->greet();

    p->setAge(35);

    delete p;

    p = nullptr;

    p->greet();  //   no dangling pointer, will more reliably fail because cannot dereference nullptr
}

// What modern C++ tries to avoid is using raw pointers to represent ownership.


int main() 
{
    tests3();
}
