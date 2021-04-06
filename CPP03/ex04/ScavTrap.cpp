/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 19:28:50 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/17 23:02:19 by kiborroq         ###   ########.fr       */
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

ScavTrap::ScavTrap(std::string const & n) : ClapTrap(n, "SC4V-TP", 100, 100, 50, 50, 1, 20, 15, 3)
{
	std::cout << *this << " I was Just born! ScavTrap class!" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << *this << " I was Just died! ScavTrap class!" << std::endl;
	return ;
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
