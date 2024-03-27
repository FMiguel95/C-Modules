#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>
#include <stdint.h>

int main()
{
	Data d;
	std::cout << d << std::endl;

	uintptr_t raw = Serializer::serialize(&d);
	std::cout << "raw:" << raw << std::endl;

	Data* d_ptr = Serializer::deserialize(raw);
	std::cout << *d_ptr << std::endl;
}
