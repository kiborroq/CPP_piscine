/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 09:28:01 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/12 11:53:37 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "string"

void	putstrUpper(std::string str)
{
	for (std::string::iterator i = str.begin(); i < str.end(); i++)
		std::cout << (char)std::toupper(*i);
}

int main(int argc, char *argv[])
{
	if (argc > 1)
		for (int i = 1; i < argc; i++)
		{
			putstrUpper(std::string(argv[i]));
			if (i < argc - 1)
				std::cout << " ";
		}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return 0;
}
