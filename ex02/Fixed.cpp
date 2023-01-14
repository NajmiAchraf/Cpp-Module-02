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

Fixed::Fixed(Fixed const &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
	this->_fixedPointValue = fixed.getRawBits();
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPointValue = fixed.getRawBits();
	return (*this);
}

int	Fixed::toInt(void) const {
	return (this->_fixedPointValue >> this->_fractionalBits);
}

float	Fixed::toFloat(void) const {
	return ((float)this->_fixedPointValue / (float)(1 << this->_fractionalBits));
}

Fixed	Fixed::operator + (Fixed const &fixed) const {
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed	Fixed::operator - (Fixed const &fixed) const {
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed	Fixed::operator * (Fixed const &fixed) const {
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed	Fixed::operator / (Fixed const &fixed) const {
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed	&Fixed::operator ++ (void) {
	this->_fixedPointValue++;
	return (*this);
}

Fixed	Fixed::operator ++ (int) {
	Fixed incremented(*this);
	this->_fixedPointValue++;
	return (incremented);
}

Fixed	&Fixed::operator -- (void) {
	thid->_frixedPointValue--;
	return(*this);
}

Fixed	Fixed::operator -- (int) {
	Fixed decremented(*this);
	this->_fixedPointValue--;
	return (decremented);
}

bool	Fixed::operator > (Fixed const &fixed) const {
	return (this->_fixedPointValue > fixed.getRawBits());
}

bool	Fixed::operator < (Fixed const &fixed) const {
	return (this->_fixedPointValue < fixed.getRawBits());
}

bool	Fixed::operator >= (Fixed const &fixed) const {
	return (this->_fixedPointValue >= fixed.getRawBits());
}

bool	Fixed::operator <= (Fixed const &fixed) const {
	return (this->_fixedPointValue <= fixed.getRawBits());
}

bool	Fixed::operator == (Fixed const &fixed) const {
	return (this->_fixedPointValue == fixed.getRawBits());
}

bool	Fixed::operator != (Fixed const &fixed) const {
	return (this->_fixedPointValue != fixed.getRawBits());
}

Fixed	&Fixed::min(Fixed &fixed1, Fixed &fixed2) {
	return (fixed1 < fixed2 ? fixed1 : fixed2);
}

Fixed	&Fixed::max(Fixed &fixed1, Fixed &fixed2) {
	return (fixed1 > fixed2 ? fixed1 : fixed2);
}

std::ostream	&operator << (std::ostream &output, Fixed const &fixed) {
	output << fixed.toFloat();
	return (output);
}
