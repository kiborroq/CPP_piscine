/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:41:50 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/17 17:05:34 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "iostream"
#include "string"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"
#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string const & n) : ClapTrap(n, "SUPER-TP", 100, 100, 120, 120, 1, 60, 20, 5), FragTrap(n), NinjaTrap(n)
{
	std::cout << *this << " I was Just born! SuperTrap class!" << std::endl;
}

SuperTrap::~SuperTrap(void)
{
	std::cout << *this << " I was Just died! SuperTrap class!" << std::endl;
	return ;
}

void SuperTrap::rangedAttack(std::string const & target)
{
	FragTrap::rangedAttack(target);
}

void SuperTrap::meleeAttack(std::string const & target)
{
	NinjaTrap::meleeAttack(target);
}
