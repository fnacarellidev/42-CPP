#pragma once
#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer {
	public:
		~Serializer();
		Serializer();
		Serializer(const Serializer& copy);
		Serializer &operator=(const Serializer &copy);
		uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);
};
