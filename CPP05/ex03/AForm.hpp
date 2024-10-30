/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 08:56:22 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/05 09:11:41 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <ctime>

//pre-definition
class Bureaucrat;

class AForm : public std::exception
{
private:
	const std::string name;
	bool _signed;
	const int grade_sign;
	const int grade_exec;

protected:
    void setSignedStatus(bool status);

public:
	// Custom exceptions within the AForm class
	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const noexcept override;
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const noexcept override;
	};
	class FormNotSignedException : public std::exception
	{
		public:
			const char* what() const noexcept override;
	};
	// Override the what() function for general exceptions
	const char* what() const noexcept override;

	// constructors
	AForm(std::string const &name, int grade_sign, int grade_exec);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
    ~AForm();

	// getters
	std::string getName() const;
	bool getSignedStatus() const;
	int getGradeSigned() const;
	int getGradeExec() const;

	// member functions
	virtual void beSigned(const Bureaucrat& bureaucrat) = 0;
	virtual void execute(const Bureaucrat& executor) const;
	virtual void action() const = 0;
	void print(std::ostream& os) const;
};

// Non-member function to overload the insertion operator
std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif
