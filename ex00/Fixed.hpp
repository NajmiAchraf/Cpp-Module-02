#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cstdlib>

class	Fixed {

	int					_fixedPointValue;
	static const int	_fractionalBits = 8;

public:

	int		getRawBits(void) const;
	void	setRawBits(int const rawBits);

	Fixed(void);
	Fixed(Fixed const &copyFixed);
	~Fixed(void);
	Fixed & operator = (Fixed const &assignFixed);

};

#endif
