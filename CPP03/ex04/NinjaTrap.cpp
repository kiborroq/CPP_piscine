/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 00:29:32 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/17 23:02:09 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "string"
#include "cstdlib"
#include "NinjaTrap.hpp"

const std::string NinjaTrap::randomKills[3] =
{
	"Another fleshbag falls to the Robolution!",
	"How do YOU like target practice? Huh? HUH?!",
	"WOO! Sucks to be a fleshie!"
};

NinjaTrap::NinjaTrap(std::string const & n) : ClapTrap(n, "INAC-TP", 60, 60, 120, 120, 1, 60, 5, 0)
{
	std::cout << *this << " I was Just born! NinjaTrap class!" << std::endl;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << *this << " I was Just died! NinjaTrap class!" << std::endl;
}

void NinjaTrap::ninjaShoebox(FragTrap & ft)
{
	killAny(ft);
}

void NinjaTrap::ninjaShoebox(ScavTrap & st)
{
	killAny(st);
}

void NinjaTrap::ninjaShoebox(NinjaTrap & nt)
{
	killAny(nt);
}

void NinjaTrap::killAny(ClapTrap & ct)
{
	if (energy < 40)
		std::cout << *this << " WTF! I have not enough erergy!" << std::endl;
	else
	{
		int i = rand() % 3;
		std::cout << *this << " " << randomKills[i] << std::endl;
		printAttackInfo(ct.getName(), "ninja", ct.getHit());
		ct.takeDamage(ct.getHit());
		energy -= 40;
	}
	printMyStatus();
}
