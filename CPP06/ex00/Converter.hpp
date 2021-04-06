/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 23:24:17 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/24 20:03:55 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

#include "istream"

class Converter
{
	private:
		bool	ischar;
		bool	isspec;
		char	c;
		double	d;
		bool	error; 

		Converter(Converter const & c);

		Converter & operator=(Converter const & c);

		bool isFloat(std::string const & suffix);
		bool isChar(std::string const & suffix);

		void castValues(void);
		void castChar(void);
		void castInt(void);
		void castFloat(void);
		void castDouble(void);

		void tryPrintChar(char c);

		std::string addPrecision(double d);

	public:
		Converter(void);
		~Converter(void);

		void display(std::string const src);
};

#endif
