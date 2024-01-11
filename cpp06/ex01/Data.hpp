#pragma once
#include <iostream>

class Data {
	public:
		int x;
		~Data();
		Data();
		Data(int num);
		Data(const Data& copy);
		Data &operator=(const Data& copy);
};
