/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 17:44:52 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/12 11:41:14 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"
#include "Colors.class.hpp"

PhoneBook::PhoneBook(void)
{
	currSize = 0;
	currIndex = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void PhoneBook::add(Contact newContact)
{
	if (currIndex >= maxSize)
		currIndex = 0;
	contacts[currIndex] = newContact;
	currIndex++;
	if (currSize < maxSize)
		currSize++;
}

void PhoneBook::search(void)
{
	std::stringstream stream;

	printHeaderPhoneBook();
	for (int i = 0; i < currSize ; i++)
	{
		stream.clear();
		stream.str("");
		stream << i;
		specialPrintField("|", stream.str(), "");
		specialPrintField("|", contacts[i].getFirstName(), "");
		specialPrintField("|", contacts[i].getLastName(), "");
		specialPrintField("|", contacts[i].getLogin(), "|");
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void PhoneBook::search(int index)
{
	if (index < currSize && index > -1)
		std::cout << contacts[index].toString();
}

void PhoneBook::printHeaderPhoneBook(void)
{
	std::cout << ("|   INDEX  | LAST NAME|FIRST NAME|   LOGIN  |") << std::endl;
}

void PhoneBook::specialPrintField(std::string pref, std::string field, std::string suf)
{
	std::cout << pref;
	std::cout << std::setw(10);
	if (field.length() > 10)
		std::cout << field.substr(0, 9) + ".";
	else
		std::cout << field;
	std::cout << suf;
}

int PhoneBook::isValidIndex(int index)
{
	if (index < 0 || index >= currSize)
		return (0);
	return (1);
}

int PhoneBook::getCurrSize(void)
{
	return (currSize);
}
