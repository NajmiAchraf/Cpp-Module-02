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

};

std::ostream & operator << (std::ostream &output, Fixed const &fixed);

#endif