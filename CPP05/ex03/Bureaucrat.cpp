/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 08:59:34 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/29 13:01:27 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

//------------------------------- Constructors ---------------------------------

//	default constructor
Bureaucrat::Bureaucrat(std::string const &name, int grade)
	: name(name), grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: name(other.name), grade(other.grade)
{
}

//copy assignment constructor
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->grade = other.getGrade();
	}
	return (*this);
}

// Deconstructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << name << " has been destroyed!" << std::endl;
}

//------------------------- Custom Exceptions Implementation --------------------------------

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
    return "Form::GradeTooHighException";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
    return "Form::GradeTooLowException";
}

//	General Exception Override
const char* Bureaucrat::what() const noexcept
{
    return "Bureaucrat exception occurred!";
}

//------------------------- Getter functions --------------------------------

std::string Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

//---------------------------- member functions -------------------------------

void Bureaucrat::incGrade(int num)
{
    if (grade - num < 1)
        throw GradeTooHighException();
    grade -= num;
}

void Bureaucrat::decGrade(int num)
{
    if (grade + num > 150)
        throw GradeTooLowException();
    grade += num;
}

//	function to sign the form
void Bureaucrat::signForm(AForm& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << name << " couldn’t sign " << form.getName()
			<< " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        // Attempt to execute the form
        form.execute(*this);
        // Success message
        std::cout << name << " executed " << form.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        // Failure message
        std::cout << name << " couldn’t execute " << form.getName()
            << " because: " << e.what() << std::endl;
    }
}

void Bureaucrat::print(std::ostream& os) const
{
    os << this->getName() << ", bureaucrat grade " << getGrade() << std::endl;
}

//------------------------- Operator Overloading --------------------------------

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    bureaucrat.print(os);
    return os;
}

