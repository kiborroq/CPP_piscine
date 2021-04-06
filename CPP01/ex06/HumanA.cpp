/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 00:44:17 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/12 20:00:11 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "string"
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon & newWeapon) : waepon(newWeapon)
{
	this->name = name;
	printMessege("I was just born!");
	return ;
}

HumanA::~HumanA(void)
{
	printMessege("I was just died!");
	return ;
}

void HumanA::attack(void) const
{
	printMessege("attacks with his " + waepon.getType() + "!");
}

void HumanA::printMessege(std::string messege) const
{
	std::cout	<< toString()
				<< messege
				<< std::endl;
}

std::string HumanA::toString(void) const
{
	return
	(
		"<" +
		name + " (humanA)" +
		">"
	);
}
