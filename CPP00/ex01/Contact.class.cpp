/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 14:51:58 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/12 11:41:53 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.class.hpp"

Contact::Contact(std::string firstName,
				std::string lastName,
				std::string login,
				std::string postalAdress,
				std::string phoneNumber,
				std::string bthDate,
				std::string favorMeal,
				std::string underWearColor,
				std::string darkestSecret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->login = login;
	this->postalAdress = postalAdress;
	this->phoneNumber = phoneNumber;
	this->bthDate = bthDate;
	this->favorMeal = favorMeal;
	this->underWearColor = underWearColor;
	this->darkestSecret = darkestSecret;
	return ;
}

Contact::Contact(void)
{
	return ;
}
Contact::~Contact(void)
{
	return ;
}

std::string Contact::toString(void)
{
	return
	(
		"first name:      " + this->firstName + "\n" +
		"last name:       " + this->lastName + "\n" +
		"login:           " + this->login + "\n" +
		"postal adress:   " + this->postalAdress + "\n" +
		"phone number:    " + this->phoneNumber + "\n" +
		"birth date       " + this->bthDate + "\n" +
		"favorite meal:   " + this->favorMeal + "\n" +
		"underwear color: " + this->underWearColor + "\n" +
		"darkest secret:  " + this->darkestSecret + "\n"
	);
}

std::string Contact::getFirstName(void)
{
	return (this->firstName);
}
std::string Contact::getLastName(void)
{
	return (this->lastName);
}
std::string Contact::getLogin(void)
{
	return (this->login);
}
std::string Contact::getPostAdress(void)
{
	return (this->postalAdress);
}
std::string Contact::getPhoneNumber(void)
{
	return (this->phoneNumber);
}
std::string Contact::getBthDate(void)
{
	return (this->bthDate);
}
std::string Contact::getFavorMeal(void)
{
	return (this->favorMeal);
}
std::string Contact::getUnderWearColor(void)
{
	return (this->underWearColor);
}
std::string Contact::getDarksetSecret(void)
{
	return (this->darkestSecret);
}

void Contact::setFirstName(std::string firstName)
{
	this->firstName = firstName;
}
void Contact::setLastName(std::string lastName)
{
	this->lastName = lastName;
}
void Contact::setLogin(std::string login)
{
	this->login = login;
}
void Contact::setPostAdress(std::string postalAdress)
{
	this->postalAdress = postalAdress;
}
void Contact::setPhoneNumber(std::string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}
void Contact::setBthDate(std::string bthDate)
{
	this->bthDate = bthDate;
}
void Contact::setFavorMeal(std::string favorMeal)
{
	this->favorMeal = favorMeal;
}
void Contact::setUnderWearColor(std::string underWearColor)
{
	this->underWearColor = underWearColor;
}
void Contact::setDarksetSecret(std::string darkestSecret)
{
	this->darkestSecret = darkestSecret;
}
