/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 18:14:05 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/19 18:24:10 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	return ;
}

Cure::Cure(Cure const & c) : AMateria(c)
{
	return ;
}

Cure::~Cure(void)
{
	return ;
}

Cure & Cure::operator=(Cure const & c)
{
	this->xp = c.getXP();
	return (*this);
}

Cure *Cure::clone(void) const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter & target)
{
	AMateria::use(target);
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
