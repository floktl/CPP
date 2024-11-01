/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 08:56:22 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/31 09:00:49 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <cstring>
#include <cstdlib>

class ScalarConverter {
private:
    ScalarConverter() {}

public:
	static void convert(const std::string& literal);
};

bool tryConvertChar(const std::string& literal);
bool tryConvertInt(const std::string& literal);
bool tryConvertFloatAndDouble(const std::string& literal);
void displayInvalidInput();

#endif