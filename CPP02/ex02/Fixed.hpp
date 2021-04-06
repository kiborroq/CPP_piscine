/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:23:04 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/12 01:29:47 by kiborroq         ###   ########.fr       */
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
		Fixed(const int point);
		Fixed(const float point);
		~Fixed(void);

		float toFloat(void) const;
		int toInt(void) const;

		Fixed & operator=(const Fixed & instance);

		bool operator>(const Fixed & instance) const;
		bool operator>=(const Fixed & instance) const;
		bool operator<(const Fixed & instance) const;
		bool operator<=(const Fixed & instance) const;
		bool operator==(const Fixed & instance) const;
		bool operator!=(const Fixed & instance) const;

		Fixed operator+(const Fixed & initstate) const;
		Fixed operator-(const Fixed & initstate) const;
		Fixed operator/(const Fixed & initstate) const;
		Fixed operator*(const Fixed & initstate) const;

		Fixed & operator++(void);
		Fixed & operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);

		static Fixed & min(Fixed & instance1, Fixed & instance2);
		static const Fixed & min(const Fixed & instance1, const Fixed & instance2);
		static Fixed & max(Fixed & instance1, Fixed & instance2);
		static const Fixed & max(const Fixed & instance1, const Fixed & instance2);

		void setRawBits(const int & rawBits);
		int getRawBits(void) const;
};

std::ostream & operator<<(std::ostream & out, const Fixed & instance);

#endif
