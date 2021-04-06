/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 18:14:05 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/20 21:16:43 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	return ;
}

Ice::Ice(Ice const & i) : AMateria(i)
{
	return ;
}

Ice::~Ice(void)
{
	return ;
}

Ice & Ice::operator=(Ice const & i)
{
	this->xp = i.getXP();
	return (*this);
}

Ice *Ice::clone(void) const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter & target)
{
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
