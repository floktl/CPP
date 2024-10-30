/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 08:56:22 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/30 09:05:34 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

//-----------------------------  Constructors --------------------------------

// Deafult constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const
	ShrubberyCreationForm &other) : AForm(other), target(other.target)
{
}

//copy assignment constructor
ShrubberyCreationForm
	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		this->target = other.getTarget();
	}
	return (*this);
}

// Deconstructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > getGradeSigned())
    {
        throw GradeTooLowException();
    }
    else
    {
        // Mark the form as signed
        setSignedStatus(true);
    }
}

//---------------------------- Getter function --------------------------------

// Getter function for target
std::string ShrubberyCreationForm::getTarget() const
{
    return target;
}

//	function to perform action of specific class
void ShrubberyCreationForm::action() const
{
	std::ofstream ofs(target + "_shrubbery");
	if (ofs)
	{
		ofs << "       ###\n"
			"      #o###\n"
			"    #####o###\n"
			"   #o#\\#|#/###\n"
			"    ###\\|/#o#\n"
			"     # }|{  #\n"
			"       }|{\n";
		ofs.close();
		std::cout << target + "_shrubbery" << " created!" << std::endl;
	}
	else
	{
		throw std::runtime_error("Error opening file.");
	}
}
