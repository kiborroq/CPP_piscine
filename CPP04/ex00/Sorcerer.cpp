/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:44:01 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/17 21:58:56 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string"
#include "iostream"
#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string const & n, std::string const & t) : name(n), title(t)
{
	std::cout << name << ", " << title << ", " << "is born!" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const & s)
{
	*this = s;
	std::cout << name << ", " << title << ", " << "is born!" << std::endl;
}

Sorcerer::~Sorcerer(void)
{
	std::cout << name << ", " << title << ", " << "is dead. Consequences will never be the same!" << std::endl;
}

Sorcerer & Sorcerer::operator=(Sorcerer const & s)
{
	this->name = s.getName();
	this->title = s.getTitle();
	return (*this);
}

void Sorcerer::polymorph(Victim const & v) const
{
	v.getPolymorphed();
}

std::string Sorcerer::getName(void) const
{
	return (this->name);
}

std::string Sorcerer::getTitle(void) const
{
	return (this->title);
}

std::ostream & operator<<(std::ostream & out, Sorcerer const & s)
{
	out << "I'm " << s.getName() << ", " << s.getTitle() << ", " << "and I like ponies!" << std::endl;
	return (out);
}
