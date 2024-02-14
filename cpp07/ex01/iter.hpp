#pragma once
#include <cstdlib>
#include <iostream>

template <typename T>
void iter(T *array, size_t size, void (*f)(T&)) {
	if (!array) return ;
	for (size_t i = 0; i < size; ++i)
		f(array[i]);
}

template <typename T>
void plusOne(T n) {
	std::cout << ++n << std::endl;
}

template <typename T>
void logString(T str) {
	std::cout << str << std::endl;
}
