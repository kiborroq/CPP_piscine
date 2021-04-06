/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 20:42:39 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/18 21:10:09 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "string"
#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const & t) : hp(hp), type(t)
{
	return ;
}

Enemy::Enemy(Enemy const & e)
{
	*this = e;
}

Enemy::~Enemy(void)
{
	return ;
}

Enemy & Enemy::operator=(Enemy const & e)
{
	this->hp = e.getHP();
	this->type = e.getType();
	return (*this);
}

void Enemy::takeDamage(int damage)
{
	if (damage > 0 && this->hp != 0)
	{
		this->hp -= damage;
		if (this->hp < 0)
			this->hp = 0;
	}
}

int Enemy::getHP(void) const
{
	return (this->hp);
}

std::string Enemy::getType(void) const
{
	return (this->type);
}
