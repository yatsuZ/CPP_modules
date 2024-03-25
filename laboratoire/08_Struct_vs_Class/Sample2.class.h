/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample2.class.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 21:54:18 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/25 01:31:11 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE2_CLASS_H
# define SAMPLE2_CLASS_H

#include <iostream>

class Sample2
{
public:
	int	foo;
	
	Sample2( void );
	~Sample2( void );

	void	bar(void) const;
};


#endif