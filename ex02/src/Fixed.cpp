#include "../inc/Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : m_value {0}
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
	// std::cout << "Copy constructor called" << std::endl;
	m_value = copy.getRawBits();
}

Fixed::Fixed(const int value) : m_value {value * 1 << m_fractionalBits}
{
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : m_value {static_cast<int>(std::roundf(value * (1 << m_fractionalBits)))}
{
	// std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& copy)
{
	// std::cout << "Copy assignment operator called" << std::endl;

	if (this != &copy)
		m_value = copy.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (m_value);
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
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

// Comparison Operators

bool Fixed::operator>(const Fixed& other) const
{
	return (m_value > other.m_value);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (m_value < other.m_value);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (m_value >= other.m_value);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (m_value <= other.m_value);
}

bool Fixed::operator==(const Fixed& other) const
{
	return (m_value == other.m_value);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (!(*this == other));
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(m_value + other.m_value);
	return (result);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(m_value - other.m_value);
	return (result);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	result.setRawBits((m_value * other.m_value) >> m_fractionalBits);
	return (result);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	result.setRawBits((m_value << m_fractionalBits) / other.m_value);
	return (result);
}

// Increment / decrement operators
Fixed& Fixed::operator++()
{
	++m_value;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp {*this};
	++m_value;
	return (temp);
}

Fixed& Fixed::operator--()
{
	--m_value;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp {*this};
	--m_value;
	return (temp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a <= b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a <= b)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a >= b)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a >= b)
		return (a);
	return (b);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}
