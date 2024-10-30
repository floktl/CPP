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

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

//-----------------------------  Constructors --------------------------------

// Deafult constructor
RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
	: AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const
	RobotomyRequestForm &other) : AForm(other), target(other.target)
{
}

//copy assignment constructor
RobotomyRequestForm
	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		this->target = other.getTarget();
	}
	return (*this);
}

// Deconstructor
RobotomyRequestForm::~RobotomyRequestForm() {}

//---------------------------- Getter function --------------------------------

// Getter function for target
std::string RobotomyRequestForm::getTarget() const
{
    return target;
}

//------------------------- member  Functions --------------------------------

// function to sign the form
void RobotomyRequestForm::beSigned(const Bureaucrat& bureaucrat)
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

//	function to perform action of specific class
void RobotomyRequestForm::action() const
{
	// Seed random number generator
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Simulate drilling noises
    std::cout << "Bzzt... Vrrrr... Drilling noises...\n";

    // 50% chance of success or failure
    if (std::rand() % 2)
    {
        std::cout << target << " has been robotomized successfully!\n";
    }
    else
    {
        std::cout << "The robotomy of " << target << " failed.\n";
    }
}
