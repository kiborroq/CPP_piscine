/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 22:58:45 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/21 18:19:05 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string"
#include "iostream"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap *Father = new ClapTrap("Father", "Clap", 200, 200, 200, 200, 5, 100, 100, 50);
	NinjaTrap *Ninja = new NinjaTrap("Ninja");
	ScavTrap *Conoco = new ScavTrap("Conoco");
	FragTrap *Genius = new FragTrap("Genius");
	std::cout << std::endl;

	Ninja->ninjaShoebox(*Father);
	std::cout << std::endl;

	Ninja->ninjaShoebox(*Conoco);
	std::cout << std::endl;

	Ninja->ninjaShoebox(*Genius);
	std::cout << std::endl;

	Ninja->beRepaired(10);
	std::cout << std::endl;

	Ninja->ninjaShoebox(*Ninja);
	std::cout << std::endl;

	delete Ninja;
	delete Conoco;
	delete Genius;
	return (0);
}
