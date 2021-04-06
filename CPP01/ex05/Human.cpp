/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 00:44:17 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/12 20:01:42 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "string"
#include "Human.hpp"

Human::Human(std::string name)
{
	this->name = name;
	myBrain = new Brain(name, 100, 100);
	printMessege("I was just born!");
	return ;
}

Human::~Human(void)
{
	delete myBrain;
	printMessege("I was just died!");
	return ;
}

std::string Human::identify(void) const
{
	return (myBrain->identify());
}

const Brain &Human::getBrain(void) const
{
	return (*myBrain);
}

void Human::printMessege(std::string messege) const
{
	std::cout	<< toString()
				<< messege
				<< std::endl;
}

std::string Human::toString(void) const
{
	return
	(
		"<" +
		name + " (human)" +
		">"
	);
}

std::string Human::getName(void) const
{
	return (name);
}
