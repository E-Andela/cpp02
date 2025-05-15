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

Fixed::Fixed(const int value) : m_value {value * 1 << m_fractionalBits}
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : m_value {static_cast<int>(std::roundf(value * (1 << m_fractionalBits)))}
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
	return (static_cast<float>(m_value) / (1 << m_fractionalBits));
}

int Fixed::toInt() const
{
	return (m_value >> m_fractionalBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}
