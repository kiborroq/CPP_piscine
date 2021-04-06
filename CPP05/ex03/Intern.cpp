/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 23:52:06 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/22 17:44:01 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	return ;
}

Intern::Intern(Intern const & i)
{
	*this = i;
}

Intern::~Intern(void)
{
	return ;
}

Intern & Intern::operator=(Intern const & i)
{
	(void)i;
	return (*this);
}

Form *Intern::makeShrubbery(std::string const & target)
{
	return (new ShrubberyCreationForm(target));
}

Form *Intern::makeRobotmy(std::string const & target)
{
	return (new RobotomyRequestForm(target));
}

Form *Intern::makePresidential(std::string const & target)
{
	return (new PresidentialPardonForm(target));
}

Form *Intern::makeForm(std::string const & form, std::string const & target) const
{
	Form *(*makers[3])(std::string const &) = {makeShrubbery, makeRobotmy, makePresidential};
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i++)
	{
		if (!form.compare(forms[i]))
			return (makers[i](target));
	}
	throw "Intern does not create form '" + form + "' because there is not exist!";
	return (NULL);
}
