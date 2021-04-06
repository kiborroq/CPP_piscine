/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 22:07:21 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/22 17:22:36 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const & t) : Form("robotomy request", 72, 45), target(t)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & rrf) : Form(rrf)
{
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return ;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rrf)
{
	this->target = rrf.getTarget();
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);
	static int successRotomize;
	successRotomize++;
	if (successRotomize % 2 == 1)
	{
		std::cout	<< "bz-bz-bzzzzz-zzzz-bz" << std::endl
					<< "bz-bzzzzz-bzzz-zzzzzz-zzzz-zzz" << std::endl
					<< "bz-zzzzz-bz-bzz-zzzzzzz-bzz-bz" << std::endl
					<< "'" << target << "' has been robotomized successfully!" << std::endl;
	}
	else
		throw "'" + target + "' has not been robotomized!";
}

std::string RobotomyRequestForm::getTarget(void) const
{
	return (this->target);
}
