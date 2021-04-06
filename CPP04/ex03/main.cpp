/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 22:45:00 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/21 19:49:48 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main(void)
{
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(NULL);
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;

	tmp = src->createMateria("known");
	me->equip(tmp);
	me->equip(NULL);
	tmp = src->createMateria("ice"); //0
	me->equip(tmp);
	tmp = src->createMateria("cure"); //1
	me->equip(tmp);
	tmp = src->createMateria("ice"); //2
	me->equip(tmp);
	tmp = src->createMateria("cure"); //3
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(-1, *bob);
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);
	std::cout << std::endl;

	me->unequip(-1);
	me->unequip(4);
	me->unequip(2);

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	
	delete bob;
	delete me;
	delete src;
	return (0);
}
