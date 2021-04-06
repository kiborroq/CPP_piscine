/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:55:40 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/19 23:02:44 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "string"
#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type), xp(0)
{
	return ;
}

AMateria::AMateria(AMateria const & m)
{
	*this = m;
}

AMateria::~AMateria(void)
{
	return ;
}

AMateria & AMateria::operator=(AMateria const & m)
{
	this->xp = m.getXP();
	this->type = m.getType();
	return (*this);
}

void AMateria::use(ICharacter & target)
{
	(void)target;
	xp += 10;
}

unsigned int AMateria::getXP(void) const
{
	return (this->xp);
}

std::string const & AMateria::getType(void) const
{
	return (this->type);
}
