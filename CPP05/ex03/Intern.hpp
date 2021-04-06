/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 23:47:21 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/22 17:40:26 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "string"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		Intern & operator=(Intern const & i);

		static Form *makeShrubbery(std::string const & target);
		static Form *makeRobotmy(std::string const & target);
		static Form *makePresidential(std::string const & target);

	public:
		Intern(void);
		Intern(Intern const & i);
		~Intern(void);

		Form *makeForm(std::string const & form, std::string const & target) const;
};

#endif
