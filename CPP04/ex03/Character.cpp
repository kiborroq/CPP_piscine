/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 20:42:02 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/21 19:43:42 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string"
#include "Character.hpp"

Character::Character(std::string name) : name(name)
{
	count = 0;
}

Character::Character(Character const & c)
{
	count = 0;
	*this = c;
}

Character::~Character(void)
{
	freeInventory();
}

Character & Character::operator=(Character const & c)
{
	name = c.getName();
	freeInventory();
	count = c.getCount();
	for (int i = 0; i < count; i++)
		inventory[i] = c.getUnit(i)->clone();
	return (*this);
}

void Character::freeInventory(void)
{
	for (int i = 0; i < count; i++)
		delete inventory[i];
	count = 0;
}

void Character::equip(AMateria *m)
{
	if (count < maxCount && m != NULL)
		inventory[count++] = m;
}

void Character::unequip(int idx)
{
	if (idx < count && idx >= 0)
	{
		count--;
		inventory[idx] = inventory[count];
		inventory[count] = NULL;
	}
}

void Character::use(int idx, ICharacter & target)
{
	if (idx < count && idx >= 0)
		inventory[idx]->use(target);
}

std::string const & Character::getName(void) const
{
	return (this->name);
}

AMateria *Character::getUnit(int idx) const
{
	if (idx < count && idx >= 0)
		return (this->inventory[idx]);
	return (NULL);
}

int Character::getCount(void) const
{
	return (this->count);
}
