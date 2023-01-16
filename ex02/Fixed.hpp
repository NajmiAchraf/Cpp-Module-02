#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cstdlib>
# include <cmath>

class	Fixed {

	int					_fixedPointValue;
	static const int	_fractionalBits = 8;

public:

	int		getRawBits(void) const;
	void	setRawBits(int const rawBits);

	Fixed(void);
	Fixed(int const newValue);
	Fixed(float const newValue);
	Fixed(Fixed const &fixed);
	~Fixed(void);
	Fixed & operator = (Fixed const &fixed);

	int		toInt(void) const;
	float	toFloat(void) const;

	Fixed	operator + (Fixed const &fixed) const;
	Fixed	operator - (Fixed const &fixed) const;
	Fixed	operator * (Fixed const &fixed) const;
	Fixed	operator / (Fixed const &fixed) const;

	Fixed	operator ++ (int);
	Fixed	operator -- (int);
	Fixed	&operator ++ (void);
	Fixed	&operator -- (void);

	bool	operator > (Fixed const &fixed) const;
	bool	operator < (Fixed const &fixed) const;
	bool	operator >= (Fixed const &fixed) const;
	bool	operator <= (Fixed const &fixed) const;
	bool	operator == (Fixed const &fixed) const;
	bool	operator != (Fixed const &fixed) const;

	static Fixed		&min(Fixed &fixed1, Fixed &fixed2);
	static Fixed		&max(Fixed &fixed1, Fixed &fixed2);
	static Fixed const	&min(Fixed const &fixed1, Fixed const &fixed2);
	static Fixed const	&max(Fixed const &fixed1, Fixed const &fixed2);

};

std::ostream	&operator << (std::ostream &output, Fixed const &fixed);

#endif
