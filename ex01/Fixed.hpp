#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cstdlib>
# include <cmath>

class	Fixed {

public:

	Fixed(void);
	Fixed(int const newValue);
	Fixed(float const newValue);
	Fixed(Fixed const &fixed);
	~Fixed(void);
	Fixed & operator = (Fixed const &fixed);

	int		getRawBits(void) const;
	void	setRawBits(int const rawBits);

	int		toInt(void) const;
	float	toFloat(void) const;


private:

	int					_fixedPointValue;
	static const int	_fractionalBits = 8;

};

std::ostream & operator << (std::ostream &out, Fixed const &fixed);

#endif