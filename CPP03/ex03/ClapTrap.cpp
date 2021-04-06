/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 19:28:50 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/17 00:14:09 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "cstdlib"
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string const & n, std::string const & t,
					int hit, int maxHit, int energy, int maxEnergy,
					int level, int meleeAttackDamage,
					int rangedAttackDamage, int armorAttackDamage) : trap(t), name(n)
{
	this->hit = hit;
	this->maxHit = maxHit;
	this->energy = energy;
	this->maxEnergy = maxEnergy;
	this->level = level;
	this->meleeAttackDamage = meleeAttackDamage;
	this->rangedAttackDamage = rangedAttackDamage;
	this->armorAttackDamage = armorAttackDamage;
	this->maxHitWithArmor = maxHit + armorAttackDamage;
	this->hitWithArmor = maxHitWithArmor;
	srand(time(NULL));
	std::cout << *this << " I was Just born! Parent class!" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << *this << " I was Just died! Parent class!" << std::endl;
	return ;
}

void ClapTrap::rangedAttack(std::string const & target)
{
	printAttackInfo(target, "range", rangedAttackDamage);
}

void ClapTrap::meleeAttack(std::string const & target)
{
	printAttackInfo(target, "melee", meleeAttackDamage);
}

void ClapTrap::takeDamage(unsigned int amount)
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

void ClapTrap::beRepaired(unsigned int amount)
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

void ClapTrap::renewHitWithArmor(void)
{
	if (hitWithArmor > 100)
		armorAttackDamage = hitWithArmor - 100;
	else
		armorAttackDamage = 0;
	hit = hitWithArmor - armorAttackDamage;
}

void ClapTrap::printMyStatus(void)
{
	std::cout	<< *this
				<< " My status: "
				<< this->hit <<" hit points, "
				<< armorAttackDamage << " armor, " 
				<< energy << " energy!"
				<< std::endl;
}

void ClapTrap::printAttackInfo(std::string const & target, std::string const & attack, unsigned int damage)
{
	std::cout	<< *this
				<< " attacks"
				<< " <" << target << "> "
				<< "at " << attack << ", causing"
				<< " <" << damage << "> points of damage!"
				<< std::endl;
}

std::string ClapTrap::getName(void) const
{
	return (this->name);
}

void ClapTrap::setName(std::string n)
{
	this->name = n;
}

int ClapTrap::getHit(void) const
{
	return (this->hit);
}

int ClapTrap::getRangedDamage(void)
{
	return (this->rangedAttackDamage);
}

int ClapTrap::getMeleeDamage(void)
{
	return (this->meleeAttackDamage);
}

std::string ClapTrap::getTrap(void) const
{
	return (this->trap);
}

void ClapTrap::setTrap(std::string t)
{
	this->trap = t;
}

std::ostream & operator<<(std::ostream & out, ClapTrap const & i)
{
	out	<< i.getTrap() << " "
		<< "<"
		<< i.getName()
		<< ">";
	return (out);
}
