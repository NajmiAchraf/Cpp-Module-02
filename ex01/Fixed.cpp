#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const newValue) : _fixedPointValue(newValue << _fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const newValue) : _fixedPointValue(roundf(newValue * (1 << _fractionalBits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
	this->_fixedPointValue = fixed.getRawBits();
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator = (Fixed const &fixed) {
	std::cout << "Copy assignation operator called" << std::endl;
	this->_fixedPointValue = fixed.getRawBits();
	return (*this);
}

std::ostream	&operator << (std::ostream &out, Fixed const &fixed) {
	out << fixed.toFloat();
	return (out);
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const rawBits) {
	this->_fixedPointValue = rawBits;
}

int		Fixed::toInt(void) const {
	return (this->_fixedPointValue >> this->_fractionalBits);
}

float	Fixed::toFloat(void) const {
	return ((float)this->_fixedPointValue / (float)(1 << this->_fractionalBits));
}
