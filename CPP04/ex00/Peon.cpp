/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 22:30:44 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/20 21:23:54 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "string"
#include "Peon.hpp"

Peon::Peon(std::string const & n) : Victim(n)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon const & p) : Victim(p)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon(void)
{
	std::cout << "Bleuark..." << 	std::endl;
}

Peon & Peon::operator=(Peon const & p)
{
	this->name = p.getName();
	return (*this);
}

void Peon::getPolymorphed(void) const
{
	std::cout << name << " has been turned into a pink pony!" << std::endl;
}
