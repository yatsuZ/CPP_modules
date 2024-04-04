/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:21:53 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/04 19:51:02 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./FileManip.hpp"

int	main(int argc, char **argv)
{
	FileManip	f(argc, argv);

	f.creatReplace();
	f.showFileManip();
}

