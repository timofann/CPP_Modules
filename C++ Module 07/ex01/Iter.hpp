#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *arr, int length, void(*fn)(T &)) {
	for (int i = 0; i < length; ++i)
		fn(arr[i]);
}

template <typename T>
void printInstance(T &instance) {
	std::cout << instance << std::endl;
}

#endif