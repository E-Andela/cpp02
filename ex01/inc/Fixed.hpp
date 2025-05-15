#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int					m_value {0};
	static const int	m_fractionalBits {8};

public:
	Fixed();
	Fixed(const Fixed& copy);
	Fixed(const int value);
	Fixed(const float value);
	Fixed& operator= (const Fixed& fixed);
	~Fixed();

	int getRawBits() const;
	void setRawBits(const int raw);
	float toFloat() const;
	int toInt() const;
};

std::ostream& operator<<(std::ostream& out, Fixed& fixed);

#endif