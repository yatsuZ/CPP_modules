/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heritage3.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:12:43 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/26 15:17:23 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Quadruped // Can acces name, run() and legs
{
private:
	std::string	name;
protected:
	int	legs[4];
public:
	void	run();
};

class Dog : public Quadruped // Can acces run() et legs
{
};

int	main() // Can only acces run()
{
}