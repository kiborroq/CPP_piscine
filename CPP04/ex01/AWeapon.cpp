/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:45:33 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/20 21:21:36 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string"
#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const & n, int apc, int d) : name(n), apCost(apc), damage(d)
{
	return ;
}

AWeapon::AWeapon(AWeapon const & a)
{
	*this = a;
}

AWeapon::~AWeapon(void)
{
	return ;
}

AWeapon & AWeapon::operator=(AWeapon const & a)
{
	this->name = a.getName();
	this->apCost = a.getAPCost();
	this->damage = a.getDamage();
	return (*this);
}

std::string AWeapon::getName(void) const
{
	return (this->name);
}

int AWeapon::getAPCost(void) const
{
	return (this->apCost);
}

int AWeapon::getDamage(void) const
{
	return (this->damage);
}