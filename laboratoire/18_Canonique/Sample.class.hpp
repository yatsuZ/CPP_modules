/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:23:07 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/26 01:38:45 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_HPP
# define SAMPLE_CLASS_HPP

# include <iostream>

class Sample
{
private:
	int	_foo;

public:
	Sample();									// CANON
	Sample( int const n);
	Sample( Sample const & src);				// CANON
	~Sample();									// CANON

	Sample	&operator=( Sample const & rhs);	// CANON

	int	getFoo(void) const;
};

std::ostream	&operator<<( std::ostream & o, Sample const & i);

#endif