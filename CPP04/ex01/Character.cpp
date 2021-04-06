/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 22:19:31 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/21 18:58:09 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "string"
#include "Character.hpp"

Character::Character(std::string const & n) : name(n), apoints(40), weapon(NULL)
{
	return ;
}

Character::Character(Character const & c)
{
	*this = c;
}

Character::~Character(void)
{
	return ;
}

Character & Character::operator=(Character const & c)
{
	this->name = c.getName();
	this->apoints = c.getAP();
	this->weapon = (AWeapon *)c.getWeapon();
	return (*this);
}

void Character::recoverAP(void)
{
	apoints += 10;
	if (apoints > 40)
		apoints = 40;
}

void Character::equip(AWeapon *w)
{
	if (w != NULL)
		this->weapon = w;
}

void Character::attack(Enemy *e)
{
	if (apoints >= weapon->getAPCost())
	{
		weapon->attack();
		apoints -= weapon->getAPCost();
		e->takeDamage(weapon->getDamage());
		if (e->getHP() <= 0)
			delete e;
	}
}

std::string Character::getName(void) const
{
	return (this->name);
}

int Character::getAP(void) const
{
	return (this->apoints);
}

const AWeapon *Character::getWeapon(void) const
{
	return (this->weapon);
}

std::ostream & operator<<(std::ostream & out, Character const & c)
{
	std::cout << c.getName() << " has " << c.getAP(); 
	if (c.getWeapon() != NULL)
		std::cout << " and wields a " << c.getWeapon()->getName();
	else
		std::cout << " and is unarmed";
	std::cout << std::endl;
	return (out);
}
