/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:23:07 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/25 23:26:03 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_HPP
# define SAMPLE_CLASS_HPP

# include <iostream>

struct Sample
{
	Sample();
	~Sample();

	void	bar( char const c) const;
	void	bar( int const n) const;
	void	bar( float const z) const;
	void	bar( Sample const & i) const;
};

#endif