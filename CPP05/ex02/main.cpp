/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:08:30 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/20 22:59:45 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void printHeader(std::string header)
{
	std::cout	<< "\033[1;35m"
				<< "<<<<< "
				<< header
				<< " >>>>>"
				<< "\033[0m"
				<< std::endl;
}

int main(void)
{
	printHeader("Bureaucrats creating!");
	Bureaucrat boss("Boss", 1);
	std::cout << boss << std::endl;
	Bureaucrat exboss("Exboss", 25);
	std::cout << exboss << std::endl;
	Bureaucrat man("Man", 70);
	std::cout << man << std::endl;
	Bureaucrat looser("Looser", 145);
	std::cout << looser << std::endl;
	std::cout << std::endl;

	printHeader("ShrubberyCreationForm test! Signing and executing ...");
	{
		Form *f1 = new ShrubberyCreationForm("home");
		std::cout << *f1 << std::endl;
		man.executeForm(*f1);
		looser.signForm(*f1);
		looser.signForm(*f1);
		boss.executeForm(*f1);
		man.executeForm(*f1);
		delete f1;
	}
	std::cout << std::endl;

	printHeader("RobotomyRequestForm test! Signing and executing ...");
	{
		Form *f1 = new RobotomyRequestForm("kitchen");
		std::cout << *f1 << std::endl;
		exboss.executeForm(*f1);
		looser.signForm(*f1);
		man.signForm(*f1);
		boss.signForm(*f1);
		man.executeForm(*f1);
		exboss.executeForm(*f1);
		std::cout << std::endl;

		Form *f2 = new RobotomyRequestForm("garden");
		exboss.signForm(*f2);
		exboss.executeForm(*f2);
		exboss.executeForm(*f2);

		delete f1;
		delete f2;
	}
	std::cout << std::endl;

	printHeader("PresidentialPardonForm test! Signing and executing ...");
	{
		Form *f1 = new PresidentialPardonForm("Intern");
		std::cout << *f1 << std::endl;
		boss.executeForm(*f1);
		man.signForm(*f1);
		exboss.signForm(*f1);
		boss.signForm(*f1);
		exboss.executeForm(*f1);
		boss.executeForm(*f1);

		delete f1;
	}
	return (0);
}
