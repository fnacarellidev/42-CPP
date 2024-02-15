#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void) {
	Base* base;
	srand(time(NULL));
	unsigned int x = rand() % 3;

	switch (x) {
		case 0:
			base = new A();
			std::cout << "Generated type A" << '\n';
			break ;
		case 1:
			base = new B();
			std::cout << "Generated type B" << '\n';
			break ;

		case 2:
			base = new C();
			std::cout << "Generated type C" << '\n';
			break ;
	}
	return base;
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Found type A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Found type B" << std::endl;
	else
		std::cout << "Found type C" << std::endl;
}

void	identify(Base &p)
{
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "Found type A" << std::endl;
	} catch (...) {
		try {
			(void)dynamic_cast<B &>(p);
			std::cout << "Found type B" << std::endl;
		} catch (...) {
			std::cout << "Found type C" << std::endl;
		}
	}
}


int main() {
	{
		std::cout << "TEST 0" << std::endl;
		Base	*ptrA = new A();
		Base	&refA = *ptrA;

		Base	*ptrB = new B();
		Base	&refB = *ptrB;

		Base	*ptrC = new C();
		Base	&refC = *ptrC;

		std::cout << "identify pointers:" << std::endl;
		identify(ptrA);
		identify(ptrB);
		identify(ptrC);

		std::cout << "identify references:" << std::endl;
		identify(refA);
		identify(refB);
		identify(refC);

		delete ptrA;
		delete ptrB;
		delete ptrC;
	}
	{
		std::cout << "TEST 1"<< std::endl;
		Base *ptr = generate();
		Base &ptrRef = *ptr;

		identify(ptr);
		identify(ptrRef);
		delete ptr;
	}
}
