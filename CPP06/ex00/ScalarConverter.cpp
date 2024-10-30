/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 08:59:34 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/30 13:41:23 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//------------------------------- Constructors ---------------------------------


//-------------------------------- exceptions ----------------------------------


//----------------------------- getter functions -------------------------------


//----------------------------- member functions -------------------------------

// Main convert function definition
void ScalarConverter::convert(const std::string& literal)
{
    if (tryConvertChar(literal)) return;
    if (tryConvertInt(literal)) return;
    if (tryConvertFloatAndDouble(literal)) return;

    displayInvalidInput();
}

// Helper function for char conversion
bool tryConvertChar(const std::string& literal)
{
    if (literal.length() == 1 && std::isprint(literal[0])
		&& !std::isdigit(literal[0]))
	{
        char charValue = literal[0];
        std::cout << "char: '" << charValue << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(charValue) << std::endl;
        std::cout << "float: " << static_cast<float>(charValue) << ".0f"
			<< std::endl;
        std::cout << "double: " << static_cast<double>(charValue) << ".0"
			<< std::endl;
        return true;
    }
    return false;
}

bool hasDecimal(const std::string& literal)
{
    size_t dotPosition = literal.find('.');
    if (dotPosition != std::string::npos) {
        return (true);
    }
    return false;
}

// Helper function for int conversion
bool tryConvertInt(const std::string& literal)
{
    try
	{
        int intValue = std::stoi(literal);

		if (hasDecimal(literal) == true)
			return false;
        std::cout << "char: ";
        if (intValue >= std::numeric_limits<char>::min() && intValue
			<= std::numeric_limits<char>::max() && std::isprint(intValue))
		{
            std::cout << "'" << static_cast<char>(intValue) << "'" << std::endl;
        }
		else
            std::cout << "Non displayable" << std::endl;

        std::cout << "int: " << intValue << std::endl;
        std::cout << "float: " << static_cast<float>(intValue) << ".0f"
			<< std::endl;
        std::cout << "double: " << static_cast<double>(intValue) << ".0"
			<< std::endl;
        return true;
    }
	catch (...)
	{
        return false;
    }
}

#include <iomanip>
#include <string>
#include <sstream>

int calculatePrecision(std::string strValue)
{

    // Find decimal point
    size_t dotPosition = strValue.find('.');
    if (dotPosition == std::string::npos) {
        return 1;  // No decimal point, so no fractional part
    }

    // Remove trailing zeros
    size_t endPosition = strValue.find_last_not_of('0');
    if (endPosition != std::string::npos && endPosition > dotPosition) {
        strValue = strValue.substr(0, endPosition + 1);
    }

    // Count digits after the decimal point
    return strValue.length() - dotPosition - 1;
}

// Helper function for float and double conversion
bool tryConvertFloatAndDouble(const std::string& literal)
{
    try
	{
        float floatValue = std::stof(literal);
        double doubleValue = std::stod(literal);

        std::cout << "char: ";
        if (floatValue >= std::numeric_limits<char>::min() && floatValue
			<= std::numeric_limits<char>::max()
			&& std::isprint(static_cast<int>(floatValue)))
		{
            std::cout << "'" << static_cast<char>(floatValue) << "'" << std::endl;
        }
		else
            std::cout << "impossible" << std::endl;

        std::cout << "int: ";
        if (floatValue >= std::numeric_limits<int>::min()
			&& floatValue <= std::numeric_limits<int>::max())
		{
            std::cout << static_cast<int>(floatValue) << std::endl;
        }
		else
            std::cout << "impossible" << std::endl;

		int precision = calculatePrecision(literal);

		std::cout << "char: '*'" << std::endl;
		std::cout << "int: " << static_cast<int>(doubleValue) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(precision) << floatValue << "f" << std::endl;
		std::cout << "double without: " << doubleValue << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(precision - 1) << doubleValue << std::endl;

        return true;
    }
	catch (...)
	{
        return false;
    }
}

// Helper function for invalid input
void displayInvalidInput()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
}
