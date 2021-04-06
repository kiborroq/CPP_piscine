/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 22:21:33 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/21 20:37:36 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string"
#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	count = 0;
}

MateriaSource::MateriaSource(MateriaSource const & ms)
{
	count = 0;
	*this = ms;
}

MateriaSource::~MateriaSource(void)
{
	freeLearnedMaterias();
}

MateriaSource & MateriaSource::operator=(MateriaSource const & ms)
{
	freeLearnedMaterias();
	count = ms.getCount();
	for (int i = 0; i < count; i++)
		learnedMaterias[i] = ms.getUnit(i)->clone();
	return (*this);
}

void MateriaSource::freeLearnedMaterias(void)
{
	for (int i = 0; i < count; i++)
		delete learnedMaterias[i];
	count = 0;
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (count < maxCount && m != NULL)
		learnedMaterias[count++] = m;
}

AMateria  *MateriaSource::createMateria(std::string const & type)
{
	for (int i = count - 1; i >= 0; i--)
	{
		if (!learnedMaterias[i]->getType().compare(type))
			return (learnedMaterias[i]->clone());
	}
	return (NULL);
}

int MateriaSource::getCount(void) const
{
	return (this->count);
}

AMateria *MateriaSource::getUnit(int i) const
{
	if (i < count && i >= 0)
		return (this->learnedMaterias[i]);
	return (NULL);
}
