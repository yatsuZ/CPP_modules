/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:27:55 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/07 19:25:58 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>
#include <limits>

#define NOCOLOR "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define PURPLE "\033[35m"

class Fixed
{
private:
	int					_rawBits;
	static const int	_coma = 8;
public:
	// Constructeur
	Fixed(void);
	Fixed(const int nbr);
	Fixed(const float nbr);
	Fixed(Fixed const & src);

	// Destructeur
	~Fixed();

	// Opperateur
	Fixed	&operator=(Fixed const & rf);

	// Conversion
	float	toFloat(void) const;
	int		toInt(void) const;

	// Autre
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

std::ostream & operator<<( std::ostream & o, Fixed const & rf);

#endif
