#include "Fixed.hpp"

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const rawBits) {
	this->_fixedPointValue = rawBits;
}

Fixed::Fixed(void) : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
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
