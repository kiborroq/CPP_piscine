/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:28:43 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/27 16:59:03 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "string"
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const char *n, int g) : name(n), grade(g)
{
	checkGrade(grade);
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & b)
{
	*this = b;
}

Bureaucrat::~Bureaucrat(void)
{
	return ;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & b)
{
	this->name = b.getName();
	this->grade = b.getGrade();
	return (*this);
}

void Bureaucrat::increment(void)
{
	checkGrade(grade - 1);
	grade--;
}

void Bureaucrat::decrement(void)
{
	checkGrade(grade + 1);
	grade++;
}

void Bureaucrat::checkGrade(int grade)
{
	if (grade > maxGrade)
		throw Bureaucrat::GradeTooLowException();
	if (grade < minGrade)
		throw Bureaucrat::GradeTooHighException();
}

const char *Bureaucrat::getName(void) const
{
	return (this->name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

std::ostream & operator<<(std::ostream & out, Bureaucrat const & b)
{
	out << "Bureaucrat " << b.getName()
		<< " has <grade>=" << b.getGrade()
		<< std::endl;
	return (out);
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade value exceeded the maximum value(1)!");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade value exceeded the minimum value(150)!");
}
