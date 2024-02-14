#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	{
		std::cout << "TEST 0 (SUBJECT)\n";
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;//
	}
	std::cout << "\n";
	{
		Array<int> intArray(10);

		std::cout << "intArray: \n";
		for (int i = 0; i < 10; ++i) {
			intArray[i] = i;
			std::cout << intArray[i] << std::endl;
		}

		Array<int> intArrayCopy(intArray);
		std::cout << "intArrayCopy: \n";
		for (int i = 0; i < 10; ++i)
			std::cout << intArrayCopy[i] << std::endl;
	}
    return 0;
}
