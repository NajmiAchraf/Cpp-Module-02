#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cstdlib>

class	Fixed {

public:

	Fixed(void);
	Fixed(Fixed const &fixed);
	~Fixed(void);
	Fixed & operator = (Fixed const &fixed);

	int		getRawBits(void) const;
	void	setRawBits(int const rawBits);


private:

	int					_fixedPointValue;
	static const int	_fractionalBits = 8;

};

#endif
