/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:28:43 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/22 17:24:39 by kiborroq         ###   ########.fr       */
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

void Bureaucrat::signForm(Form & f) const
{
	try
	{
		if (f.getSign() == false)
		{
			f.beSigned(*this);
			std::cout	<< *this << " signs " << f << std::endl;
		}
		else
			std::cout << *this << " cannot sign " << f << " because one's already signed" << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << *this << " cannot sign " << f << " because has too low grade!" << std::endl;
	}
	catch(std::string & e)
	{
		std::cout << e << std::endl;
	}
}

void Bureaucrat::executeForm(Form const & f) const
{
	try
	{
		if (f.getSign() == true)
		{
			f.execute(*this);
			std::cout	<< *this << " executes " << f << std::endl;
		}
		else
			std::cout << *this << " cannot execute " << f << " because one does not sign!" << std::endl;
	}
	catch(std::string & e)
	{
		std::cout << e << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << *this << " cannot execute " << f << " because has too low grade!" << std::endl;
	}
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
	out << "Bureaucrat '" << b.getName()
		<< "' <g=" << b.getGrade()
		<< ">";
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
