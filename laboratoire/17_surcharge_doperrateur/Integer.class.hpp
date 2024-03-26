/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Integer.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:43:36 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/26 01:14:22 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTEGER_CLASS_HPP
# define INTEGER_CLASS_HPP

# include <iostream>

class Integer {
	int _n;
public:
	
	Integer( int const n);
	~Integer( void );

	int		getValue(void) const;

	Integer	&operator=( Integer const & rhs);
	Integer	operator+( Integer const & rhs) const;
};

std::ostream & operator<<( std::ostream & o, Integer const & rhs);

#endif