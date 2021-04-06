/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:06:34 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/17 23:09:14 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "string"
#include "Victim.hpp"

Victim::Victim(std::string const & n) : name(n)
{
	std::cout << "Some random victim called " << name << " just appeared!" << std::endl;
}

Victim::Victim(Victim const & v)
{
	*this = v;
	std::cout << "Some random victim called " << name << " just appeared!" << std::endl;
}

Victim::~Victim(void)
{
	std::cout << "Victim " << name << " just died for no apparent reason!" << std::endl;
}

Victim & Victim::operator=(Victim const & v)
{
	this->name = v.getName();
	return (*this);
}

void Victim::getPolymorphed(void) const
{
	std::cout << name << " has been turned into a cute little sheep!" << std::endl;
}

std::string Victim::getName(void) const
{
	return (this->name);
}

std::ostream & operator<<(std::ostream & out, Victim const & v)
{
	out << "I'm " << v.getName() << " and I like otters!" << std::endl;
	return (out);
}
