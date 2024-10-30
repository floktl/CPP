/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 08:59:34 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/30 09:37:51 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

//------------------------------- Constructors ---------------------------------

// default Constructor
Form::Form(std::string const &name, int grade_sign, int grade_exec)
: name(name), _signed(false), grade_sign(grade_sign), grade_exec(grade_exec)
{
    if (grade_sign < 1 || grade_exec < 1)
        throw GradeTooHighException();
    if (grade_sign > 150 || grade_exec > 150)
        throw GradeTooLowException();
}

// Copy constructor
Form::Form(const Form &other)
    : name(other.name), _signed(other._signed),grade_sign(other.grade_sign),
		grade_exec(other.grade_exec)
{
}

//Copy assignment Constructor
Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return *this;
}

// Deconstructor
Form::~Form()
{
	std::cout << "Form " << name << " has been destroyed!" << std::endl;
}

//------------------------- Custom Exceptions Implementation --------------------------------

const char* Form::GradeTooHighException::what() const noexcept
{
    return "Form::GradeTooHighException";
}

const char* Form::GradeTooLowException::what() const noexcept
{
    return "Form::GradeTooLowException!";
}

//	General Exception Override
const char* Form::what() const noexcept
{
    return "Form exception occurred!";
}

const char*	Form::AlreadySignedException::what() const noexcept
{
	return "Form::AlreadySignedException!";
}

//------------------------- Getter functions --------------------------------

std::string Form::getName() const
{
    return name;
}

bool Form::getSignedStatus() const
{
    return _signed;
}

int Form::getGradeSigned() const
{
    return grade_sign;
}

int Form::getGradeExec() const
{
    return grade_exec;
}

//---------------------------- member functions -------------------------------

//	fucntion to sign the form
void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if ( _signed == true)
	{
		throw AlreadySignedException();
	}
    if (bureaucrat.getGrade() > grade_sign)
        throw GradeTooLowException();
    _signed = true;
}

//	function to print all class
void Form::print(std::ostream& os) const
{
    os << "Form name: " << getName()
		<< ", signed: " << (getSignedStatus() ? "Yes" : "No")
		<< ", grade required to sign: " << getGradeSigned()
		<< ", grade required to execute: " << getGradeExec() << std::endl;
}

//------------------------- Operator Overloading --------------------------------

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    form.print(os);
    return os;
}

