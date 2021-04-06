/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 10:21:32 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/22 17:20:28 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "stdexcept"
# include "iostream"
# include "Form.hpp"

class Form;
class Bureaucrat
{
	private:
		const char	*name;
		static const int	maxGrade = 150;
		static const int	minGrade = 1;
		int					grade;

		Bureaucrat(void);

		void checkGrade(int grade);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

	public:
		Bureaucrat(const char *n, int g);
		Bureaucrat(Bureaucrat const & b);
		~Bureaucrat(void);

		Bureaucrat & operator=(Bureaucrat const & b);

		void increment(void);
		void decrement(void);
		void signForm(Form & f) const;
		void executeForm(Form const & f) const;

		const char *getName(void) const;
		int getGrade(void) const;
};

std::ostream & operator<<(std::ostream & out, Bureaucrat const & b);

#endif
