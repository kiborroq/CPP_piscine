/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:13:13 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/28 16:21:17 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>

typedef struct sData
{
	std::string *s1;
	int         num;
	std::string *s2;
}               Data;

void printInfo(std::string const & s1, int num, std::string const & s2)
{
	std::cout << "s1:  " << s1 << std::endl;
	std::cout << "num: " << num << std::endl;
	std::cout << "s2:  " << s2 << std::endl;
}

std::string *getRandomString(void)
{
	int			strLength;
	std::string	str;
	std::string	charSet = "abcdefghijklmnopqrstuvwxyz ,;.'{} 0123456789 ABSCDEFGHIJKLMOPQRSTUVWXYZ";

	strLength = 5 + rand() % 95;
	str.resize(strLength);
	for (int i = 0; i < strLength; i++)
		str[i] = charSet[rand() % charSet.length()];
	return (new std::string(str));
}

void *serialize(void)
{
	srand(time(NULL));

	void *mem = ::operator new (2 * sizeof(std::string *) + sizeof(int));
	void *tmp = mem;

	std::string *s1 = getRandomString();
	int num = rand();
	std::string *s2 = getRandomString();;
	printInfo(*s1, num, *s2);

	*reinterpret_cast<std::string **>(tmp) = s1;
	tmp = reinterpret_cast<std::string **>(tmp) + 1;
	*reinterpret_cast<int *>(tmp) = num;
	tmp = reinterpret_cast<int *>(tmp) + 1;
	*reinterpret_cast<std::string **>(tmp) = s2;

	return (mem);
}

Data *deserialize(void *mem)
{
	Data *data = new Data;

	data->s1 = *reinterpret_cast<std::string **>(mem);
	mem = reinterpret_cast<std::string **>(mem) + 1;
	data->num = *reinterpret_cast<int *>(mem);
	mem = reinterpret_cast<int *>(mem) + 1;
	data->s2 = *reinterpret_cast<std::string **>(mem);

	return (data);
}

int main(void)
{
	std::cout << "<<< SERIALIZE >>>" << std::endl;
	void *mem = serialize();
	std::cout << std::endl;

	std::cout << "<<< DESERIALIZE >>>" << std::endl;
	Data *data = deserialize(mem);
	printInfo(*data->s1, data->num, *data->s2);

	::operator delete(mem);
	delete data->s1;
	delete data->s2;
	delete data;
	return (0);
}
