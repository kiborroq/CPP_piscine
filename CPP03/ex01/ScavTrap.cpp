/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 19:28:50 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/17 00:04:24 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "cstdlib"
#include "ScavTrap.hpp"

const std::string ScavTrap::randomChallengs[5] =
{
	"Did you try to open me?",
	"A door. How impressive.",
	"Ugh... your door smells like feces with a vomit garnish! Please give me some transmitters so I may relocate myself somewhere with a higher average income!",
	"Wrong door, you inebriate!",
	"You do realize you're standing in front of a hilariously large door, don't you?"
};

ScavTrap::ScavTrap(std::string const & n) : name(n)
{
	hit = 100;
	maxHit = 100;
	energy = 50;
	maxEnergy = 50;
	level = 1;
	meleeAttackDamage = 20;
	rangedAttackDamage = 15;
	armorAttackDamage = 3;
	maxHitWithArmor = maxHit + armorAttackDamage;
	hitWithArmor = 	maxHitWithArmor;
	srand(time(NULL));
	std::cout << *this << " I was Just born for" << std::endl;
	printMyStatus();
}

ScavTrap::~ScavTrap(void)
{
	std::cout << *this << " I was Just died!" << std::endl;
	return ;
}

void ScavTrap::rangedAttack(std::string const & target)
{
	printAttackInfo(target, "range", rangedAttackDamage);
}

void ScavTrap::meleeAttack(std::string const & target)
{
	printAttackInfo(target, "melee", meleeAttackDamage);
}

void ScavTrap::takeDamage(unsigned int amount)
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

void ScavTrap::beRepaired(unsigned int amount)
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

void ScavTrap::renewHitWithArmor(void)
{
	if (hitWithArmor > 100)
		armorAttackDamage = hitWithArmor - 100;
	else
		armorAttackDamage = 0;
	hit = hitWithArmor - armorAttackDamage;
}

void ScavTrap::challengeNewcomer(void)
{
	if (energy < 25)
		std::cout << *this << " WTF! I have not enough erergy!" << std::endl;
	else
	{
		int i = rand() % 5;
		std::cout << *this << " " << randomChallengs[i] << std::endl;
		energy -= 25;
	}
	printMyStatus();
}

void ScavTrap::printMyStatus(void)
{
	std::cout	<< *this
				<< " My status: "
				<< this->hit <<" hit points, "
				<< armorAttackDamage << " armor, " 
				<< energy << " energy!"
				<< std::endl;
}

void ScavTrap::printAttackInfo(std::string const & target, std::string const & attack, unsigned int damage)
{
	std::cout	<< *this
				<< " attacks"
				<< " <" << target << "> "
				<< "at " << attack << ", causing"
				<< " <" << damage << "> points of damage!"
				<< std::endl;
}

std::string ScavTrap::getName(void) const
{
	return (this->name);
}

void ScavTrap::setName(std::string n)
{
	this->name = n;
}

int ScavTrap::getHit(void) const
{
	return (this->hit);
}

int ScavTrap::getRangedDamage(void)
{
	return (this->rangedAttackDamage);
}

int ScavTrap::getMeleeDamage(void)
{
	return (this->meleeAttackDamage);
}

std::ostream & operator<<(std::ostream & out, ScavTrap const & i)
{
	out	<< "SC4V-TP" << " "
		<< "<"
		<< i.getName()
		<< ">";
	return (out);
}
