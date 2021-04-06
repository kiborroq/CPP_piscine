/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 19:28:50 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/21 13:54:39 by kiborroq         ###   ########.fr       */
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

FragTrap::FragTrap(std::string const & n) : name(n)
{
	hit = 100;
	maxHit = 100;
	energy = 100;
	maxEnergy = 100;
	level = 1;
	meleeAttackDamage = 30;
	rangedAttackDamage = 20;
	armorAttackDamage = 5;
	randomAttackDamage = 0;
	maxHitWithArmor = maxHit + armorAttackDamage;
	hitWithArmor = 	maxHitWithArmor;
	srand(time(NULL));
	std::cout << *this << " I was Just born!" << std::endl;
	printMyStatus();
}

FragTrap::~FragTrap(void)
{
	std::cout << *this << " I was Just died!" << std::endl;
	return ;
}

void FragTrap::rangedAttack(std::string const & target)
{
	printAttackInfo(target, "range", rangedAttackDamage);
}

void FragTrap::meleeAttack(std::string const & target)
{
	printAttackInfo(target, "melee", meleeAttackDamage);
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

void FragTrap::takeDamage(unsigned int amount)
{
	hitWithArmor -= amount;
	if (hitWithArmor < 0)
	{
		std::cout << *this << " They damaged me for " << hitWithArmor + amount << " HP!" << std::endl;;
		hitWithArmor = 0;
	}
	else
		std::cout << *this << " They damaged me for " << amount << " HP!" << std::endl;;
	renewHitWithArmor();
	printMyStatus();
}

void FragTrap::beRepaired(unsigned int amount)
{
	hitWithArmor += amount;
	if (hitWithArmor > maxHitWithArmor)
	{
		hitWithArmor = maxHitWithArmor;
		std::cout << *this << " They tried to reapiar me for " << amount << " HP!" << std::endl;
	}
	else
		std::cout << *this << " They reapiared me for " << amount << " HP!" << std::endl;
	renewHitWithArmor();
	printMyStatus();
}

void FragTrap::renewHitWithArmor(void)
{
	if (hitWithArmor > 100)
		armorAttackDamage = hitWithArmor - 100;
	else
		armorAttackDamage = 0;
	hit = hitWithArmor - armorAttackDamage;
}

void FragTrap::printMyStatus(void)
{
	std::cout	<< *this
				<< " My status: "
				<< this->hit <<" hit points, "
				<< armorAttackDamage << " armor, " 
				<< energy << " energy!"
				<< std::endl;
}

void FragTrap::printAttackInfo(std::string const & target, std::string const & attack, unsigned int damage)
{
	std::cout	<< *this
				<< " attacks"
				<< " <" << target << "> "
				<< "at " << attack << ", causing"
				<< " <" << damage << "> points of damage!"
				<< std::endl;
}

std::string FragTrap::getName(void) const
{
	return (this->name);
}

void FragTrap::setName(std::string n)
{
	this->name = n;
}

int FragTrap::getHit(void) const
{
	return (this->hit);
}

int FragTrap::getRandomDamage(void)
{
	return (this->randomAttackDamage);
}

int FragTrap::getRangedDamage(void)
{
	return (this->rangedAttackDamage);
}

int FragTrap::getMeleeDamage(void)
{
	return (this->meleeAttackDamage);
}

std::ostream & operator<<(std::ostream & out, FragTrap const & i)
{
	out	<< "FR4G-TP" << " "
		<< "<"
		<< i.getName()
		<< ">";
	return (out);
}
