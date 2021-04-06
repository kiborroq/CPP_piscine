/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 22:04:38 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/22 17:05:56 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private:
		std::string target;

		RobotomyRequestForm(void);

	public:
		RobotomyRequestForm(std::string const & t);
		RobotomyRequestForm(RobotomyRequestForm const & rrf);
		virtual ~RobotomyRequestForm(void);

		RobotomyRequestForm & operator=(RobotomyRequestForm const & rrf);

		virtual void execute(Bureaucrat const & executor) const;

		std::string getTarget(void) const;
};

#endif
