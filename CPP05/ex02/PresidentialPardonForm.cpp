/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 08:56:22 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/28 05:56:19 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

//-----------------------------  Constructors --------------------------------

// Deafult constructor
PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
	: AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const
	PresidentialPardonForm &other) : AForm(other), target(other.target)
{
}

//copy assignment constructor
PresidentialPardonForm
	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		this->target = other.getTarget();
	}
	return (*this);
}

// Deconstructor
PresidentialPardonForm::~PresidentialPardonForm() {}

//---------------------------- Getter function --------------------------------

// Getter function for target
std::string PresidentialPardonForm::getTarget() const
{
    return target;
}

//------------------------- member  Functions --------------------------------

// function to sign the form
void PresidentialPardonForm::beSigned(const Bureaucrat& bureaucrat)
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
void PresidentialPardonForm::action() const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox."
		<< std::endl;
}
