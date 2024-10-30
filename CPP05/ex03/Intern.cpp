/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 08:56:22 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/28 05:56:19 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>

//------------------------------- Constructors --------------------------------

// default Constructor
Intern::Intern() {}

// Copy constructor
Intern::Intern(const Intern &other)
{
	(void)other;
}

//Copy assignment Constructor
Intern &Intern::operator=(const Intern &other)
{
	if (this != &other)
    {
    }
    return *this;
}

// Deconstructor
Intern::~Intern() {}

//------------------------ custom exceptions ------------------------------

const char* Intern::InvalidFormExecption::what() const noexcept
{
    return "Intern::InvalidFormExecption";
}

//------------------------- member Functions ------------------------------

//	function to create a form using an array of class function pointers
AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    // Array of structs to hold form names and corresponding creation functions
    struct FormType
    {
        std::string name;
        AForm* (*createForm)(const std::string& target);
    };

    // Populate the array with known form types
	FormType formTypes[] = {
        { "shrubbery creation", [](const std::string& target) -> AForm*
			{ return new ShrubberyCreationForm(target); }},
        { "robotomy request", [](const std::string& target) -> AForm*
			{ return new RobotomyRequestForm(target); }},
        { "presidential pardon", [](const std::string& target) -> AForm*
			{ return new PresidentialPardonForm(target); }}
    };

    // Iterate over the array to find the matching form name
    for (int i = 0; i < 3; ++i)
    {
        if (formTypes[i].name == formName)
        {
            std::cout << "Intern creates " << formName << " Form" << std::endl;
            return formTypes[i].createForm(target);
        }
    }
    // If no match is found, print an error
    std::cout << RED << "Error:" << RESET << " Form type " << YELLOW << formName
		<< RESET << " does not exist." << std::endl;
	throw InvalidFormExecption();
}