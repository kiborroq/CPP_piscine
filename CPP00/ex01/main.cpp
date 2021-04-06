/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:20:54 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/12 11:56:02 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"
#include "Colors.class.hpp"

void printWelcome(void)
{
	std::cout   << Colors::darkBlue("Hello! This is simple phonebook.") << std::endl
				<< Colors::darkBlue("Phonebook knows only three command: ADD, SEARCH and EXIT.") << std::endl
				<< Colors::blue("ADD: new contanct add") << std::endl
				<< Colors::blue("SEARCH: display a list of the available contacts") << std::endl
				<< Colors::blue("EXIT: the program quits") << std::endl
				<< Colors::darkBlue("Let's start!") << std::endl << std::endl;
}

int	translateInput(std::string input)
{
	if (!input.compare("ADD"))
		return (1);
	if (!input.compare("SEARCH"))
		return (2);
	if (!input.compare("EXIT"))
		return (3);
	return (0);
}

std::string inputField(std::string nameField)
{
	std::string field("");

	while (!field.length())
	{
		std::cout << Colors::blue(nameField + ": ");
		std::getline(std::cin, field);
	}
	return (field);
}

int isNum(std::string str)
{
	for (std::string::iterator i = str.begin(); i < str.end(); i++)
	{
		if (*i < '0' || *i > '9')
			return (0);
	}
	return (1);
}

int inputIndex(void)
{
	std::string 		indexField;
	std::stringstream	converter;
	int					index;

	indexField = inputField("contact index");
	if (isNum(indexField))
	{
		converter << indexField;
		converter >> index;
	}
	else
		index = -1;
	return (index);
}

void addContact(PhoneBook *phones)
{
	std::cout << Colors::darkBlue("Enter contact’s information:") << std::endl;
	Contact newContact
	(
		inputField("first name"),
		inputField("last name"),
		inputField("login"),
		inputField("postal adress"),
		inputField("phone number"),
		inputField("birth date"),
		inputField("favorite meal"),
		inputField("underwear color"),
		inputField("darkest secret")
	);
	phones->add(newContact);
	std::cout << Colors::green("Contact has been successfully created!") << std::endl;
}

void searchPhoneBook(PhoneBook *phones)
{
	int					index;
	std::string			num;

	phones->search();
	if (phones->getCurrSize() == 0)
	{
		std::cout << Colors::darkBlue("Now phonebook is empty. You should create a new contact!") << std::endl;
		return ;
	}
	std::cout << Colors::darkBlue("Enter any contact index for detail information: ") << std::endl;
	index = inputIndex();
	if (phones->isValidIndex(index))
		phones->search(index);
	else	
		std::cout << Colors::red("Index isn't valid!") << std::endl;
}

int main(void)
{
	PhoneBook	phones;
	std::string input;
	int			command;

	printWelcome();
	while (true)
	{
		std::cout << Colors::pink("PHONEBOOK >> ");
		std::getline(std::cin, input);
		command = translateInput(input);
		switch (command)
		{
			case 1:
				addContact(&phones);
				break;
			case 2:
				searchPhoneBook(&phones);
				break;
			case 3:
				return (0);
				break;
			default:
				break;
		}
	}
	return (0);
}
