/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 21:16:38 by kiborroq          #+#    #+#             */
/*   Updated: 2021/03/12 20:38:38 by kiborroq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string"
#include "iostream"
#include "fstream"

std::string getFileName(char *filename)
{
	std::string filenameReplase;

	while (*filename)
	{
		filenameReplase += std::toupper(*filename);
		filename++;
	}
	return (filenameReplase + ".replace");
}

void replase(std::string s1, std::string s2,
			std::ifstream & fin, std::ofstream & fout)
{
	std::string buf;

	while (!fin.eof() && !fout.fail())
	{
		if (!getline(fin, buf))
			break ;
		for (size_t i = 0; i < buf.length(); i++)
		{
			if (!buf.compare(i, s1.length(), s1))
			{
				buf.replace(i, s1.length(), s2);
				i += s2.length();
			}
		}
		fout << buf;
		if (!fin.eof())
		 	fout << std::endl;
	}
}

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::ifstream fin(argv[1]);
		if (fin.fail())
		{
			std::cerr << "Error during input file opening!" << std::endl;
			return (0);
		}
		std::ofstream fout(getFileName(argv[1]));
		if (fout.fail())
		{
			std::cerr << "Error during output file opening!" << std::endl;
			fin.close();
			return (0);
		}
		replase(argv[2], argv[3], fin, fout);
		if (!fin.eof() && (fin.fail() || fout.fail()))
			std::cerr << "Error during input/output file reading/writing!" << std::endl;
		fin.close();
		fout.close();
	}
	else
		std::cerr << "Number of arguments -sn't valid!" << std::endl;
	return (0);
}
