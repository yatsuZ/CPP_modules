/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:28:10 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/29 18:42:07 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMPORT_H
# define IMPORT_H

#include <iostream>
#include <string>

char	*get_input(char *msg);
int		is_good_name(char *str);
int		is_a_legit_number_phone(char *str);

#endif