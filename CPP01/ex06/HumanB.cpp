/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 00:44:17 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/12 20:16:03 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "string"
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->waepon = NULL;
	printMessege("I was just born!");
	return ;
}

HumanB::~HumanB(void)
{
	printMessege("I was just died!");
	return ;
}

void HumanB::attack(void) const
{
	printMessege("attacks with his " + waepon->getType() + "!");
}

void HumanB::setWeapon(Weapon & weapon)
{
	this->waepon = &weapon;
}

void HumanB::printMessege(std::string messege) const
{
	std::cout	<< toString()
				<< messege
				<< std::endl;
}

std::string HumanB::toString(void) const
{
	return
	(
		"<" +
		name + " (humanB)" +
		">"
	);
}
