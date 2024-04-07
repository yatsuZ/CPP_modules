/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:27:55 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/07 18:36:20 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					_rawBits;
	static const int	_coma = 8;
public:
	Fixed(void);
	Fixed(const int nbr);
	Fixed(const float nbr);
	Fixed(Fixed const & src);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	
// d'affectation 
	Fixed	&operator=(Fixed const & rf);
// BONUS

	Fixed	&operator+=(Fixed const & rf);
	Fixed	&operator-=(Fixed const & rf);
	Fixed	&operator*=(Fixed const & rf);
	Fixed	&operator/=(Fixed const & rf);

// operrateur mathematic
	Fixed	operator+(Fixed const & rf);
	Fixed	operator-(Fixed const & rf);
	Fixed	operator*(Fixed const & rf);
	Fixed	operator/(Fixed const & rf);

// Comparaison logique
	bool	operator>(Fixed const & rf) const;
	bool	operator<(Fixed const & rf) const;
	bool	operator<=(Fixed const & rf) const;
	bool	operator>=(Fixed const & rf) const;
	bool	operator==(Fixed const & rf) const;
	bool	operator!=(Fixed const & rf) const;

// Accrementation / Deccrementation
	Fixed	operator++(void);// post
	Fixed	operator++(int);// pre
	Fixed	operator--(void);// post
	Fixed	operator--(int);// pre

	Fixed	operator-(void);

	static Fixed	min(Fixed const & rf1, Fixed const & rf2);
	static const Fixed	minConst(Fixed const & rf1, Fixed const & rf2);
	static Fixed	max(Fixed const & rf1, Fixed const & rf2);
	static const Fixed	maxConst(Fixed const & rf1, Fixed const & rf2);
};

std::ostream & operator<<( std::ostream & o, Fixed const & rf);

float	ft_pow(float base, int pow);

#endif
