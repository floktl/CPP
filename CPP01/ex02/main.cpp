/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:57:26 by flo               #+#    #+#             */
/*   Updated: 2024/09/12 08:24:12 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string"
#include "iostream"

int main(void)
{
	std::string greeting = "HI THIS IS BRAIN";
	std::string *stringPTR = &greeting;
	std::string &stringREF = greeting;

	// memory adresses
	std::cout << &greeting << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;
	// values
	std::cout << greeting << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
	return (0);
}
