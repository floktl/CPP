/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:16:29 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/31 08:01:37 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		ScalarConverter::convert(argv[1]);
	}
	else if (argc == 1)
	{
		// Test cases
		std::string testLiterals[] =
		{
			"42",           //	Integer literal
			"42.0f",        //	Float literal
			"42.0",         //	Double literal
			"a",            //	Single char literal
			"nan",          //	Special double literal (not a number)
			"inf",          //	Positive infinity
			"-inf",         //	Negative infinity
			"2147483647",   //	Max int
			"-2147483648",  //	Min int
			"128.5f",       //	Float with fractional part
			"127",          //	Max signed char as int
			"non-numeric",  //	Invalid literal
			""				//	empty literal
		};
		for (const std::string& literal : testLiterals)
		{
			std::cout << "Testing literal: \"" << literal << "\"" << std::endl;
			ScalarConverter::convert(literal);
			std::cout << std::string(40, '-') << std::endl;
		}
	}
	else
	{
		std::cout << "not more than 2 arguments allowed" << std::endl;
	}
    return 0;
}

