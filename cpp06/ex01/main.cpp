#include "Serializer.hpp"
#include <cstdlib>

int main() {
	{
		std::cout << "TEST 0" << std::endl;
		Data		*ptr = new Data(4422);
		uintptr_t	uintPtr;
		Data		*deserializedPtr;

		uintPtr = Serializer::serialize(ptr);
		deserializedPtr = Serializer::deserialize(uintPtr);

		std::cout << "default ptr: " << ptr->x << std::endl;
		std::cout << "deserialized ptr: " << deserializedPtr->x << std::endl;
		delete ptr;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 1" << std::endl;
		srand(time(NULL));
		Data		*ptr = new Data(rand() % 1000);

		uintptr_t uintPtr = Serializer::serialize(ptr);
		Data *deserializedPtr = Serializer::deserialize(uintPtr);

		std::cout << "default ptr (random): " << ptr->x << std::endl;
		std::cout << "deserialized ptr (random): " << deserializedPtr->x << std::endl;
		delete ptr;
	}
	return 0;
}
