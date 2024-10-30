/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 08:59:34 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/28 10:04:46 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//------------------------------- Constructors ---------------------------------

// default Constructor
Bureaucrat::Bureaucrat(std::string const &name, int grade)
    : name(name), grade(grade)
{
    try
	{
        if (grade < 1)
            throw GradeTooHighException();
        else if (grade > 150)
            throw GradeTooLowException();
    }
	catch (std::exception& e)
	{
		//	it would make more sense to implement the error message directly here
        throw;
    }
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

//------------------------------- exceptions ---------------------------------

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
    return "Bureaucrat::GradeTooHighException";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
    return "Bureaucrat::GradeTooLowException";
}

const char* Bureaucrat::what() const noexcept
{
    return "Bureaucrat general exception occurred";
}

//--------------------------- getter functions -------------------------------

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

std::string	Bureaucrat::getName() const
{
	return (this->name);
}


//---------------------------- member functions -------------------------------

// Increment grade
void Bureaucrat::incGrade(int num)
{
    try
	{
        if (grade - num < 1)
            throw GradeTooHighException();
        grade -= num;
    } catch (std::exception& e)
	{
		//	it would make more sense to implement the error message directly here
        throw;
    }
}

// Decrement grade
void Bureaucrat::decGrade(int num)
{
    try
	{
        if (grade + num > 150)
            throw GradeTooLowException();
        grade += num;
    }
	catch (std::exception& e)
	{
		//	it would make more sense to implement the error message directly here
        throw;
    }
}

//	function to print the name and value
void Bureaucrat::print(std::ostream& os) const
{
    os << this->getName() << ", bureaucrat grade " << getGrade() << std::endl;
}

//------------------------- Operator Overloading --------------------------------

std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat)
{
    Bureaucrat.print(os);
    return os;
}
