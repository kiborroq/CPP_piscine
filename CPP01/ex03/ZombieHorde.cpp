/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 22:11:15 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/12 20:03:55 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string"
#include "cstdlib"
#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int numZombie, std::string type)
{
	this->numZombie = numZombie;
	this->type = type;
	createHorde();
	return ;
}

ZombieHorde::~ZombieHorde(void)
{
	delete []horde;
	return ;
}

void ZombieHorde::announce(void) const
{
	for (int i = 0; i < numZombie; i++)
		horde[i].announce();
}

void ZombieHorde::createHorde(void)
{
	horde = new Zombie[numZombie];
	srand(time(NULL));
	for (int i = 0; i < numZombie; i++)
	{
		horde[i].setName(getRandomName());
		horde[i].setType(type);
	}
}

std::string ZombieHorde::getRandomName(void)
{
	const int	nameLength = 7;
	std::string	name;
	std::string	charSet = "abacadefejehijikilmnopoqorstuvuwuxyzy";

	name.resize(nameLength);
	for (int i = 0; i < nameLength; i++)
		name[i] = charSet[rand() % charSet.length()];
	return (name);
}

Zombie *ZombieHorde::getZombieHorde(void) const
{
	return (horde);
}

int ZombieHorde::getNumZombie(void) const
{
	return (numZombie);
}
