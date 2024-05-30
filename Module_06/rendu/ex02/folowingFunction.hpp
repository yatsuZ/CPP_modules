/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   folowingFunction.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:43:45 by yzaoui            #+#    #+#             */
/*   Updated: 2024/05/30 13:57:30 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOLOWINGFUNCTION_HPP
# define FOLOWINGFUNCTION_HPP

#include "./Base/Base.hpp"

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);
int		generateARandom(int range);

#endif