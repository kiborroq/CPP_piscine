/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 13:19:41 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/20 21:13:41 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "Form.hpp"

Form::Form(const char *n, int sg, int eg) : name(n), signGrade(sg), executeGrade(eg), sign(false)
{
	checkGrade(signGrade);
	checkGrade(executeGrade);
}

Form::Form(Form const & f) : name(f.getName()), signGrade(f.getSignGrade()), executeGrade(f.getExecuteGrade()), sign(f.getSign())
{
	return ;
}

Form::~Form(void)
{
	return ;
}

Form & Form::operator=(Form const & f)
{
	this->name = f.getName();
	this->sign = f.getSign();
	return (*this);
}

void Form::beSigned(Bureaucrat const & b)
{
	if (b.getGrade() > signGrade)
		throw Form::GradeTooLowException();
	sign = true;
}

void Form::checkGrade(int grade)
{
	if (grade > maxGrade)
		throw Form::GradeTooLowException();
	if (grade < minGrade)
		throw Form::GradeTooHighException();
}

const char *Form::getName(void) const
{
	return (this->name);
}

int Form::getSignGrade(void) const
{
	return (this->signGrade);
}

int Form::getExecuteGrade(void) const
{
	return (this->executeGrade);
}

bool Form::getSign(void) const
{
	return (this->sign);
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade value exceeded the maximum value(1)!");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade value exceeded the minimum value(150)!");
}

std::ostream & operator<<(std::ostream & out, Form const & f)
{
	out << std::boolalpha;
	out << "Form " << f.getName()
		<< " <s=" << f.getSign()
		<< " sg=" << f.getSignGrade()
		<< " eg=" << f.getExecuteGrade()
		<< ">";
	return (out);
}
