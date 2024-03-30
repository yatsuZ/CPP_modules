/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:28:10 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/30 01:12:54 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMPORT_H
# define IMPORT_H

#include <iostream>
#include <string>

std::string	get_input(std::string msg);
int		is_good_name(std::string str);
int		is_a_legit_number_phone(std::string str);

#endif