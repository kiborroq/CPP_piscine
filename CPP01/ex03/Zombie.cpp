/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:48:07 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/12 20:02:21 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "string"
#include "Zombie.hpp"

Zombie::Zombie(void)
{
	this->name = "";
	this->type = "";
	return ;
}

Zombie::Zombie(std::string name, std::string type)
{
	this->name = name;
	this->type = type;
	printMessege("I was just born!");
	return ;
}

Zombie::~Zombie(void)
{
	printMessege("I was just died!");
	return ;
}

void Zombie::announce(void) const
{
	printMessege("Braiiiiiiinnnssss...");
}

void Zombie::printMessege(std::string messege) const
{
	std::cout	<< toString()
				<< messege
				<< std::endl;
}

std::string Zombie::toString(void) const
{
	return
	(
		"<" +
		name + " " +
		"(" + type + ")" +
		">"
	);
}

void Zombie::setName(std::string name)
{
	this->name = name;
}

void Zombie::setType(std::string type)
{
	this->type = type;
}

std::string Zombie::getName(void) const
{
	return (name);
}

std::string Zombie::getType(void) const
{
	return (name);
}