/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:23:04 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/13 19:08:08 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include "iostream"

class Fixed
{
	private:
		int					rawBits;
		static const int	fracBits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed & instance);
		~Fixed(void);

		Fixed & operator=(const Fixed & instance);

		void setRawBits(const int & rawBits);
		int getRawBits(void) const;
};

#endif
