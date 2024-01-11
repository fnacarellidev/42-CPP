#include "Serializer.hpp"

Serializer::~Serializer() {}

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &obj) { (void)obj; }

Serializer &Serializer::operator=(const Serializer &other) {
	(void)other;
	return (*this);
}
