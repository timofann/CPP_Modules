#ifndef DATA_HPP
#define DATA_HPP
#include <cstdint>

struct Data {
	char            b;
	unsigned int    a;
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif