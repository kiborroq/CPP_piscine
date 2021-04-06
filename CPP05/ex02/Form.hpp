/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 13:06:33 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/20 22:02:52 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "iostream"
# include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
	private:
		const char	*name;
		const int	signGrade;
		const int	executeGrade;
		bool		sign;

		static const int	maxGrade = 150;
		static const int	minGrade = 1;

		Form(void);

		void checkGrade(int grade);

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

	public:
		Form(const char *n, int sg, int eg);
		Form(Form const & f);
		virtual ~Form(void);

		Form & operator=(Form const & f);

		void beSigned(Bureaucrat const & b);
		virtual void execute(Bureaucrat const & executor) const = 0;

		const char *getName(void) const;
		int getSignGrade(void) const;
		int getExecuteGrade(void) const;
		bool getSign(void) const;
};

std::ostream & operator<<(std::ostream & out, Form const & f);

#endif
