/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 20:45:24 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/20 21:51:30 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "string"
# include "Form.hpp"

class PresidentialPardonForm : public Form
{
	private:
		std::string target;

		PresidentialPardonForm(void);

	public:
		PresidentialPardonForm(std::string const & t);
		PresidentialPardonForm(PresidentialPardonForm const & ppf);
		virtual ~PresidentialPardonForm(void);

		PresidentialPardonForm & operator=(PresidentialPardonForm const & ppf);

		virtual void execute(Bureaucrat const & executor) const;

		std::string getTarget(void) const;
};

#endif
