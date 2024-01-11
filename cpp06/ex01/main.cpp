#include "Serializer.hpp"
#include <cstdlib>

int main() {
	{
		std::cout << "TEST 1" << std::endl;
		Data		*ptr = new Data(42);
		uintptr_t	uintPtr;
		Data		*deserializePtr;

		uintPtr = Serializer::serialize(ptr);
		deserializePtr = Serializer::deserialize(uintPtr);

		std::cout << "data ptr original, value:\t" << ptr->x << std::endl;
		std::cout << "data ptr deserialize, value:\t" << deserializePtr->x << std::endl;
		delete	ptr;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 2" << std::endl;
		srand(time(NULL));
		Data		*ptr = new Data(rand() % 10);
		uintptr_t	uintPtr;
		Data		*deserializePtr;

		uintPtr = Serializer::serialize(ptr);
		deserializePtr = Serializer::deserialize(uintPtr);

		std::cout << "data ptr original, value:\t" << ptr->x << std::endl;
		std::cout << "data ptr deserialize, value:\t" << deserializePtr->x << std::endl;
		delete	ptr;
	}
	return 0;
}
