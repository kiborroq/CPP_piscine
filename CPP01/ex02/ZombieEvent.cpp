/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:21:23 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/12 20:06:50 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string"
#include "cstdlib"
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(std::string zombieType)
{
	this->zombieType = zombieType;
	srand(time(NULL));
	return ;
}

ZombieEvent::~ZombieEvent(void){return ;}

void ZombieEvent::setZombieType(std::string zombieType)
{
	this->zombieType = zombieType;
}

Zombie *ZombieEvent::newZombie(std::string name) const
{
	return (new Zombie(name, zombieType));
}

void ZombieEvent::randomChump(void) const
{
	Zombie randomZombie(getRandomName(), zombieType);
	randomZombie.printMessege("I want your Braiiiiiiinnnssss...");
	randomZombie.announce();
}

std::string ZombieEvent::getRandomName(void) const
{
	const int	nameLength = 7;
	std::string	name;
	std::string	charSet = "abacadefejehijikilmnopoqorstuvuwuxyzy";

	name.resize(nameLength);
	for (int i = 0; i < nameLength; i++)
		name[i] = charSet[rand() % charSet.length()];
	return (name);
}
