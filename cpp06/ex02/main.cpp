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
		dynamic_cast<A &>(p);
		std::cout << "Found type A" << std::endl;
	} catch (...) {
		try {
			dynamic_cast<B &>(p);
			std::cout << "Found type B" << std::endl;
		} catch (...) {
			std::cout << "Found type C" << std::endl;
		}
	}
}


int main() {
	identify(generate());
	identify(generate());
	identify(generate());
	identify(generate());
	identify(generate());
	identify(generate());
}
