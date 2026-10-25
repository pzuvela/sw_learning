#include <iostream>
#include "person.h"

/*
raw pointer
    -> just remembers an address
    -> can become dangling
    -> cannot detect destruction

weak_ptr
    -> does not own the object
    -> tracks shared_ptr-managed lifetime
    -> can detect that the object expired
*/


int main()
{

	std::weak_ptr<Person> weak;

	{
	    std::shared_ptr<Person> shared =
	        std::make_shared<Person>("Alice", 30);

	    weak = shared;

	    if (auto p = weak.lock())
	    {
	        p->greet();   // valid
	    }
	}

	// shared is destroyed here
	// Person is also destroyed because owner count reaches 0

	if (auto p = weak.lock())
	{
	    p->greet();
	}
	else
	{
	    std::cout << "Person no longer exists\n";
	}

	std::cout << "Object gone? " << weak.expired() << '\n';

}
