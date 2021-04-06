/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 14:26:08 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/12 11:59:19 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTANCT_CLASS_HPP
# define CONTANCT_CLASS_HPP

# include <string>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string login;
		std::string postalAdress;
		std::string phoneNumber;
		std::string bthDate;
		std::string favorMeal;
		std::string underWearColor;
		std::string darkestSecret;

	public:
		Contact (void);
		Contact(std::string firstName,
				std::string lastName,
				std::string login,
				std::string postalAdress,
				std::string phoneNumber,
				std::string bthDate,
				std::string favorMeal,
				std::string underWearColor,
				std::string darkestSecret);
		~Contact(void);

		std::string toString(void);

		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getLogin(void);
		std::string getPostAdress(void);
		std::string getPhoneNumber(void);
		std::string getBthDate(void);
		std::string getFavorMeal(void);
		std::string getUnderWearColor(void);
		std::string getDarksetSecret(void);

		void setFirstName(std::string firstName);
		void setLastName(std::string lastName);
		void setLogin(std::string login);
		void setPostAdress(std::string postalAdress);
		void setPhoneNumber(std::string phoneNumber);
		void setBthDate(std::string bthDate);
		void setFavorMeal(std::string favorMeal);
		void setUnderWearColor(std::string underWearColor);
		void setDarksetSecret(std::string darkestSecret);
};

#endif