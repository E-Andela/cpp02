#include "../inc/Fixed.hpp"
#include <iostream>

int main()
{
	const Fixed a(-5);
	const Fixed b(2);

	Fixed		c(4.2f);
	Fixed		d(1);

	std::cout << "raw values: " << a.getRawBits() << ", " << b.getRawBits() << std::endl;
	std::cout << std::endl;

	std::cout << "(a > b) = " << (a > b) << std::endl;
	std::cout << "(a < b) = " << (a < b) << std::endl;
	std::cout << "(a >= b) = " << (a >= b) << std::endl;
	std::cout << "(a <= b) = " << (a <= b) << std::endl;
	std::cout << "(a == b) = " << (a == b) << std::endl;
	std::cout << "(a != b) = " << (a != b) << std::endl;
	std::cout << std::endl;

	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a - b = "<< a - b << std::endl;
	std::cout << "a * b = " << a * b << std::endl;
	std::cout << "a / b = " << a / b << std::endl;
	std::cout << std::endl;

	std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;
	std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl;
	std::cout << "a.max(a, b) = " << a.max(a, b) << std::endl;
	std::cout << "max(a, c) = " << Fixed::max(a, c) << std::endl;
	std::cout << std::endl;

	Fixed	e;

	std::cout << "e: " << e << std::endl;
	std::cout << "++e: " << ++e << std::endl;
	std::cout << "e: " << e << std::endl;
	std::cout << "e++: " << e++ << std::endl;
	std::cout << "e: " << e << std::endl;
}