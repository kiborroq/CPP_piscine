/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 22:58:45 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/17 17:18:56 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string"
#include "iostream"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int main(void)
{
	SuperTrap *Super = new SuperTrap("Super");
	NinjaTrap *Ninja = new NinjaTrap("Ninja");
	ScavTrap *Conoco = new ScavTrap("Conoco");
	FragTrap *Genius = new FragTrap("Genius");
	std::cout << std::endl;

	Super->meleeAttack(Conoco->getName());
	std::cout << std::endl;

	Super->rangedAttack(Genius->getName());
	std::cout << std::endl;

	Super->vaulthunter_dot_exe(Ninja->getName());
	std::cout << std::endl;	

	Super->ninjaShoebox(*Genius);
	std::cout << std::endl;

	Super->takeDamage(60);
	std::cout << std::endl;

	Super->beRepaired(80);
	std::cout << std::endl;

	delete Ninja;
	delete Conoco;
	delete Genius;
	delete Super;
	return (0);
}
