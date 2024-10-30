/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 08:59:34 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/30 09:03:28 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

//------------------------------- Constructors ---------------------------------

// default Constructor
AForm::AForm(std::string const &name, int grade_sign, int grade_exec)
    : name(name), _signed(false), grade_sign(grade_sign), grade_exec(grade_exec)
{
    if (grade_sign < 1 || grade_exec < 1)
        throw GradeTooHighException();
    if (grade_sign > 150 || grade_exec > 150)
        throw GradeTooLowException();
}

// Copy constructor
AForm::AForm(const AForm &other)
    : name(other.name), _signed(other._signed),grade_sign(other.grade_sign),
		grade_exec(other.grade_exec)
{
}

//Copy assignment Constructor
AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return *this;
}

// Deconstructor
AForm::~AForm()
{
	std::cout << "AForm " << name << " has been destroyed!" << std::endl;
}

//------------------------------- exceptions ---------------------------------

const char* AForm::GradeTooHighException::what() const noexcept
{
    return "AForm::GradeTooHighException";
}

const char* AForm::GradeTooLowException::what() const noexcept
{
    return "AForm::GradeTooLowException!";
}

const char* AForm::FormNotSignedException::what() const noexcept
{
    return "AForm::FormNotSignedException!";
}

//	General Exception Override
const char* AForm::what() const noexcept
{
    return "AForm exception occurred!";
}

//------------------------- Getter/setter functions ----------------------------
std::string AForm::getName() const
{
    return name;
}

bool AForm::getSignedStatus() const
{
    return _signed;
}

int AForm::getGradeSigned() const
{
    return grade_sign;
}

int AForm::getGradeExec() const
{
    return grade_exec;
}

void AForm::setSignedStatus(bool status)
{
    _signed = status;
}

//------------------------- member Functions ------------------------------

//	function to sign the form
void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > grade_sign)
        throw GradeTooLowException();
    _signed = true;
}

void AForm::execute(const Bureaucrat& executor) const
{
	if (getSignedStatus() != true)
		throw FormNotSignedException();
    else if (executor.getGrade() > grade_sign)
        throw GradeTooLowException();
	action();
}

void AForm::print(std::ostream& os) const
{
    os << "AForm name: " << getName()
	<< ", signed: " << (getSignedStatus() ? "Yes" : "No")
	<< ", grade required to sign: " << getGradeSigned()
	<< ", grade required to execute: " << getGradeExec() << std::endl;
}


//------------------------- Operator Overloading --------------------------------

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    form.print(os);
    return os;
}

