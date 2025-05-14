#include "../inc/Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : m_value {0}
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	m_value = copy.getRawBits();
}

Fixed::Fixed(const int value) : m_value {value * static_cast<int>(pow(2, m_fractionalBits))}
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : m_value {static_cast<int>(value * pow(2, m_fractionalBits))}
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& copy)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &copy)
		m_value = copy.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (m_value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	m_value = raw;
}

float Fixed::toFloat() const
{
	return (m_value * pow(2, -m_fractionalBits));
}

int Fixed::toInt() const
{
	return (m_value * pow(2, -m_fractionalBits));
}