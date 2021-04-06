/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 20:45:24 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/22 17:06:00 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP

# include "string"
# include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	private:
		std::string target;

		ShrubberyCreationForm(void);

	public:
		ShrubberyCreationForm(std::string const & t);
		ShrubberyCreationForm(ShrubberyCreationForm const & scf);
		virtual ~ShrubberyCreationForm(void);

		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & scf);

		virtual void execute(Bureaucrat const & executor) const;

		std::string getTarget(void) const;
};

#endif
