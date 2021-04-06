/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:16:48 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/28 12:17:52 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include "stdexcept"
# include "iostream"
# include "vector"

class span
{
	private:
		unsigned int		N;
		std::vector<int>	v;
		unsigned int		minSpan;
		unsigned int		maxSpan;
		unsigned int		prevSize;

		span(void);
		span(span const & s);
		span & operator=(span const & s);

		void renewMinMaxSpan(void);

		class TooMuchNumbersException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

		class TooLowNumbersException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

	public:
		span(unsigned int n);
		~span(void);

		void addNumber(int num);

		template <typename InpuIterator>
		void addRange(InpuIterator begin, InpuIterator end)
		{
			if (v.size() + (end - begin) <= N)
			{
				v.insert(v.end(), begin, end);
				renewMinMaxSpan();
			}
			else
				throw TooMuchNumbersException();
		}

		unsigned int shortestSpan(void) const;
		unsigned int longestSpan(void) const;

		unsigned int size(void) const;
};

#endif
