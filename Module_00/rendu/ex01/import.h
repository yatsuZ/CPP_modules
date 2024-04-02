/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:28:10 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/02 02:01:23 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMPORT_H
# define IMPORT_H

// Import de library

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <iomanip>
#include <sstream>

// Fonction utile pour tout.

std::string	get_input(std::string msg);
int		is_good_name(std::string str);
int		is_a_legit_number_phone(std::string str);
void	put_the_right_lenght(std::string str);
void	put_the_right_lenght(int i);

#endif