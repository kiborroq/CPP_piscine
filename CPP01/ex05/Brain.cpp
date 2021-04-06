/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 00:14:09 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/12 20:01:30 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "sstream"
#include "Brain.hpp"

Brain::Brain(std::string ownerName, int iq, int degreeOfTaste)
{
	this->iq = iq;
	this->degreeOfTaste = degreeOfTaste;
	this->ownerName = ownerName;
	printMessege("I was just born!");
	return ;
}

Brain::~Brain(void)
{
	printMessege("I was just died!");
	return ;
}

std::string Brain::identify(void) const
{
	std::stringstream stream;

	stream << this;
	return (stream.str());
}

void Brain::printMessege(std::string messege) const
{
	std::cout	<< toString()
				<< messege
				<< std::endl;
}

std::string Brain::toString(void) const
{
	return
	(
		"<" +
		ownerName + " (brain)"
		">"
	);
}
