/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 19:28:50 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/21 13:58:54 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "cstdlib"
#include "FragTrap.hpp"

const std::string FragTrap::randomAttacks[5] =
{
	"Freeze! I don't know why I said that.",
	"Eat bomb, baddie!",
	"Remember, use caution near an open flame!",
	"Da, da da da! It's electric!",
	"Things are exploded and... stuff."
};

const int FragTrap::randomDameges[5] =
{
	25,
	30,
	40,
	35,
	50,
};

FragTrap::FragTrap(std::string const & n) : ClapTrap(n, "FR4G-TP", 100, 100, 100, 100, 1, 30, 20, 5)
{
	randomAttackDamage = 0;
	std::cout << *this << " I was Just born! FragTrap class!" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << *this << " I was Just died! FragTrap class!" << std::endl;
	return ;
}

void FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	if (energy < 25)
	{
		std::cout << *this << " WTF! I have not enough erergy!" << std::endl;
		randomAttackDamage = 0;
	}
	else
	{
		int i = rand() % 5;
		randomAttackDamage = randomDameges[i];
		std::cout << *this << " " << randomAttacks[i] << std::endl;
		printAttackInfo(target, "random", randomAttackDamage);
		energy -= 25;
	}
	printMyStatus();
}

int FragTrap::getRandomDamage(void)
{
	return (this->randomAttackDamage);
}
