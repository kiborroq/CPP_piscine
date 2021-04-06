/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:58:26 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/19 23:14:19 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "Squad.hpp"

Squad::Squad(void)
{
	count = 0;
	return ;
}

Squad::Squad(Squad const & s)
{
	count = 0;
	*this = s;
}

Squad::~Squad(void)
{
	freeSquad();
}

Squad & Squad::operator=(Squad const & s)
{
	freeSquad();
	count = s.getCount();
	for (int i = 0; i < count; i++)
		this->squad[i] = s.getUnit(i)->clone();
	return (*this);
}

void Squad::freeSquad(void)
{
	for (int i = 0; i < count; i++)
		delete squad[i];
	count = 0;
}

ISpaceMarine *Squad::getUnit(int i) const
{
	if (i < count && i >= 0)
		return (this->squad[i]);
	return (NULL);
}

int Squad::push(ISpaceMarine *sm)
{
	int iInSquad = isInSquard(sm);
	if (iInSquad >= 0)
		return (iInSquad);
	if (sm != NULL && count < maxCount)
	{
		squad[count] = sm;
		return (count++);
	}
	return (-1);
}

int Squad::isInSquard(ISpaceMarine *sm)
{
	for (int i = 0; i < count; i++)
	{
		if (squad[i] == sm)
			return (i);
	}
	return (-1);
}

int Squad::getCount(void) const
{
	return (this->count);
}
