#pragma once
#include <algorithm>
#include <iostream>

template <typename T>
bool easyfind(T intArray, int toFind) {
	if (std::find(intArray.begin(), intArray.end(), toFind) == intArray.end()) {
		std::cout << "Couldn't find: " << toFind << '\n';
		return false;
	}
	std::cout << "Found: " << toFind << '\n';
	return true;
}
