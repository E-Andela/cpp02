#include "../inc/Fixed.hpp"
#include <iostream>

int main()
{
	Fixed a(10);
	Fixed b(10.01f);

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;

	std::cout << a.toFloat() << std::endl;
	std::cout << b.toFloat() << std::endl;

	std::cout << a.toInt() << std::endl;
	std::cout << b.toInt() << std::endl;
}