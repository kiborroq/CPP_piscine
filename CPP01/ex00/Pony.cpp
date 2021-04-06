/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:15:11 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/12 20:08:19 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "string"
#include "sstream"
#include "Phony.hpp"

Phony::Phony(std::string nickname, std::string color, int age)
{
	this->nickname = nickname;
	this->color = color;
	this->age = age;
	std::cout 	<< "I was just born!" << " "
				<< toString() << std::endl;
	return ;
}

Phony::~Phony(void)
{
	std::cout 	<< "I was just died!" << " "
				<< toString() << std::endl;
	return ;
}

std::string Phony::toString(void) const
{
	std::stringstream stream;

	stream << age;
	return
	(
		"Nickname: " + nickname + ", " +
		"color: " + color + ", " +
		"age: " + stream.str() + "."
	);
}
