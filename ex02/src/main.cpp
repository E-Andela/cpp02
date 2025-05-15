#include "../inc/Fixed.hpp"
#include <iostream>

int main()
{
	const Fixed a(-5);
	const Fixed b(2);

	std::cout << "raw values: " << a.getRawBits() << ", " << b.getRawBits() << std::endl;

	std::cout << (a > b) << std::endl;
	std::cout << (a < b) << std::endl;
	std::cout << (a >= b) << std::endl;
	std::cout << (a <= b) << std::endl;
	std::cout << (a == b) << std::endl;
	std::cout << (a != b) << std::endl;

	std::cout << a + b << std::endl;
	std::cout << a - b << std::endl;
	std::cout << a * b << std::endl;
	std::cout << a / b << std::endl;

	int i{0};
	std::cout << i++ << std::endl;
	std::cout << i << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;
}