/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:26:27 by fernacar          #+#    #+#             */
/*   Updated: 2023/11/29 21:50:29 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream> 
#include <cstring>

int	main(int ac, char **av)
{
	if (ac != 4 || !av[2][0])
	{
		if (ac != 4)
			std::cerr << "Usage: ./sed <filename> <string1> <string2>" << std::endl;
		if (!av[2][0])
			std::cerr << "<string1> can't be empty" << std::endl;
		return (1);
	}

	std::string in_file_name  = av[1];
	std::string from_str	  = av[2];
	std::string to_str		  = av[3];
	std::string out_file_name = in_file_name + ".replace";

	// open input file
	std::ifstream infile(in_file_name.c_str());
	if (!infile)
	{
		std::cerr << in_file_name << ": " << std::strerror(errno) << std::endl;
		return (1);
	}
	
	// create output file
	std::ofstream outfile(out_file_name.c_str());
	if (!outfile)
	{
		std::cerr << out_file_name << ": " << std::strerror(errno) << std::endl;
		return (1);
	}

	// read from input file
	std::string f_contents = "";
	for (std::string line; std::getline(infile, line); ) 
	{
		f_contents.append(line);
		if (!infile.eof())
			f_contents.push_back('\n');
	}
	infile.close();

	// replace strings
	std::size_t pos = 0;
	do
	{
		pos = f_contents.find(from_str, pos);
		if (pos != std::string::npos)
		{
			f_contents.erase(pos, from_str.length());
			f_contents.insert(pos, to_str);
			pos += to_str.length();
		}
	} while (pos != std::string::npos);
	
	// write result to output file
	outfile.write(f_contents.c_str(), f_contents.length());
	outfile.close();

	return (0);
}
/* Tests

a
aa
aaa
aaaa
abcdef abcdef
aabbccddeeff
ola  adeus

./sed
./sed doesnotexist a b
./sed test a b
./sed test a a
./sed test a aa
./sed test aa a
./sed test abc def
./sed test " " ""
./sed test "" ""

*/