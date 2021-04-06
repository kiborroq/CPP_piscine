/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:08:30 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/22 17:39:43 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

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
	Intern intern;
	try
	{
		printHeader("Bureaucrat 'Boss' creating");
		Bureaucrat boss("Boss", 1);
		std::cout << boss << std::endl;
		std::cout << std::endl;

		printHeader("Intern creates 'presidential pardon form'...");
		Form *ppf = intern.makeForm("presidential pardon", "Looser");
		std::cout << "Intern creates form " << *ppf << std::endl;
		boss.signForm(*ppf);
		boss.executeForm(*ppf);
		delete ppf;
		std::cout << std::endl;

		printHeader("Intern creates 'robotomy request form'...");
		Form *rrf = intern.makeForm("robotomy request", "Kitchen");
		std::cout << "Intern creates form " << *rrf << std::endl;
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf;
		std::cout << std::endl;

		printHeader("Intern creates 'shrubbery creation form'...");
		Form *scf = intern.makeForm("shrubbery creation", "Garden");
		std::cout << "Intern creates form " << *scf << std::endl;
		boss.signForm(*scf);
		boss.executeForm(*scf);
		delete scf;
		std::cout << std::endl;

		printHeader("Intern creates 'known form'...");
		Form *knonw = intern.makeForm("known form", "empty");
		std::cout << *knonw << std::endl;
		boss.signForm(*knonw);
		boss.executeForm(*knonw);
		delete knonw;
	}
	catch(std::string & e)
	{
		std::cout << e << std::endl;
	}
	return (0);
}
