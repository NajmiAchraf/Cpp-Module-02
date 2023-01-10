#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cstdlib>

class	Fixed {

public:

	int		getRawBits(void) const;
	void	setRawBits(int const rawBits);

	Fixed(void);
	Fixed(Fixed const &fixed);
	~Fixed(void);
	Fixed & operator = (Fixed const &fixed);

private:

	int					_fixedPointValue;
	static const int	_fractionalBits = 8;

};

#endif
