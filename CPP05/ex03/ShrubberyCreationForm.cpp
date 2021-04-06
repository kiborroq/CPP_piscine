/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 20:57:02 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/22 17:11:16 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "fstream"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & t) : Form("shrubbery creation", 145, 137), target(t)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & scf) : Form(scf)
{
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return ;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & scf)
{
	this->target = scf.getTarget();
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);
	std::ofstream fout(target + "_shrubbery");
	if (!fout.fail())
	{
		fout	<< "          .     .  .      +     .      .          .\n"
				<< "     .       .      .     #       .           .\n"
				<< "        .      .         ###            .      .      .\n"
				<< "      .      .   \"#:. .:##\"##:. .:#\"  .      .\n"
				<< "          .      . \"####\"###\"####\"  .\n"
				<< "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       .\n"
				<< "  .             \"#########\"#########\"        .        .\n"
				<< "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       .\n"
				<< "     .     .  \"#######\"\"##\"##\"\"#######\"                  .\n"
				<< "                .\"##\"#####\"#####\"##\"           .      .\n"
				<< "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .\n"
				<< "      .     \"#######\"##\"#####\"##\"#######\"      .     .\n"
				<< "    .    .     \"#####\"\"#######\"\"#####\"    .      .\n"
				<< "            .     \"      000      \"    .     .\n"
				<< "       .         .   .   000     .        .       .\n"
				<< ".. .. ..................O000O........................ ...... ...\n";
	}
	else
		throw "Error during output file opening!";
}

std::string ShrubberyCreationForm::getTarget(void) const
{
	return (this->target);
}
