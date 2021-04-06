/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 10:21:32 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/20 13:21:48 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "stdexcept"
# include "iostream"
# include "string"

class Bureaucrat
{
	private:
		const char	*name;
		int			grade;

		static const int	maxGrade = 150;
		static const int	minGrade = 1;

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

		const char *getName(void) const;
		int getGrade(void) const;
};

std::ostream & operator<<(std::ostream & out, Bureaucrat const & b);

#endif
