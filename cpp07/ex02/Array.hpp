#pragma once
#include <iostream>
#include <cstdlib>
#include <stdexcept>

template <typename T>
class Array {
	private:
		size_t _size;
		T *_array;
	public:
		~Array() {
			if (_size > 0 && _array)
				delete[] _array;
#ifdef DEBUG
			std::cout << "[ARRAY] Destructor called" << '\n';
#endif
		};
		Array() {
			_size = 0;
			_array = NULL;
		};
		Array(const Array& copy) {
			_size = 0;
			if (this != &copy)
				*this = copy;
		};
		Array(size_t size) {
			this->_size = size;
			_array = new T[size];
		};
		T& operator[](size_t index) {
			if (index >= this->_size)
				throw (std::exception());
			return _array[index];
		};
		Array& operator=(const Array &copy) {
			size_t copy_size = copy._size;

			if (this != &copy) {
				this->~Array();
				if (copy_size > 0) {
					new(this) Array(copy_size);
					for (size_t i = 0; i < copy_size; ++i)
						this->_array[i] = copy._array[i];
				}
			}
			return *this;
		}
		size_t size() {
			return _size;
		};
};
