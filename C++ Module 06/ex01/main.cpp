#include "Data.hpp"
#include <iostream>

int main() {

	Data my_data;

	my_data.a = 25;
	my_data.b = 'b';

	std::cout << &my_data << std::endl;
	std::cout << &(my_data.a) << std::endl;
	std::cout << my_data.a << std::endl;
	std::cout << (int *)(&(my_data.b)) << std::endl;
	std::cout << my_data.b << std::endl;

	std::cout << "-----------------------" << std::endl;

	Data *new_data = deserialize(serialize(&my_data));
	std::cout << new_data << std::endl;
	std::cout << &(new_data->a) << std::endl;
	std::cout << new_data->a << std::endl;
	std::cout << (int *)(&(new_data->b)) << std::endl;
	std::cout << new_data->b << std::endl;
}