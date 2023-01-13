#include "Fixed.hpp"

int	Fixed::getRawBits(void) const {
    return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const rawBits) {
	this->_fixedPointValue = rawBits;
}

Fixed::Fixed(void) : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const newValue) : _fixedPointValue(newValue << this->_fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const newValue) : _fixedPointValue(roundf(newValue * (1 << this->_fractionalBits))) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copyFixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copyFixed;
	this->_fixedPointValue = copyFixed.getRawBits();
}

Fixed	&Fixed::operator=(const Fixed &assignFixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPointValue = assignFixed.getRawBits();
	return (*this);
}

int	Fixed::toInt() const {
	return (this->_fixedPointValue >> this->_fractionalBits);
}

float	Fixed::toFloat() const {
	return (roundf((float)this->_fixedPointValue * (float)(1 >> this->_fractionalBits)));
}
