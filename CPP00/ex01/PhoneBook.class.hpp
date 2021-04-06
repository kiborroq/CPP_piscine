/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 14:22:03 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/12 11:40:56 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include <string>
# include "Contact.class.hpp"

class PhoneBook
{
	private:
		static const int	maxSize = 8;
		int					currSize;
		int					currIndex;
		Contact				contacts[maxSize];

		void specialPrintField(std::string pref, std::string field, std::string suf);
		void printHeaderPhoneBook(void);
	
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void add(Contact contact);
		void search(void);
		void search(int index);
		int	isValidIndex(int index);

		int getCurrSize(void);
};

#endif
