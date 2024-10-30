/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:16:29 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/30 09:57:41 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// ANSI color codes for output styling
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define PURPLE  "\033[35m"

int main()
{
    // Test 1: Creating a Bureaucrat with the lowest valid grade
    std::cout << "\nRunning Test 1: Creating a Bureaucrat with the lowest "
		<< "valid grade (150)" << std::endl;
    try
    {
        Bureaucrat a("hello", 150);
        std::cout << a << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Test 1 failed: " << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Test 1 failed: " << e.what() << std::endl;
    }

    // Test 2: Creating a Bureaucrat with the highest valid grade
    std::cout << "\nRunning Test 2: Creating a Bureaucrat with the highest "
		<< "valid grade (1)" << std::endl;
    try
    {
        Bureaucrat b("hello", 1);
        std::cout << b << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Test 2 failed: " << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Test 2 failed: " << e.what() << std::endl;
    }

    // Test 3: Decreasing grade below the minimum
	//	(should throw GradeTooLowException)
    std::cout << "\nRunning Test 3: Decreasing grade below the minimum "
		<< "for grade 150" << std::endl;
    try
    {
        Bureaucrat a("hello", 150);
        a.decGrade(1);
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Test 3 failed: " << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Test 3 failed: " << e.what() << std::endl;
    }

    // Test 4: Increasing grade above the maximum
	//	(should throw GradeTooHighException)
    std::cout << "\nRunning Test 4: Increasing grade above the maximum for "
		<< "grade 1" << std::endl;
    try
    {
        Bureaucrat b("hello", 1);
        b.incGrade(1);
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Test 4 failed: " << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Test 4 failed: " << e.what() << std::endl;
    }

    // Test 5: Creating a Bureaucrat with an invalid grade (too low, 151)
    std::cout << "\nRunning Test 5: Creating Bureaucrat with an invalid grade "
		<< "(too low, 151)" << std::endl;
    try
    {
        Bureaucrat c("hello", 151);
        std::cout << c << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Test 5 failed: " << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Test 5 failed: " << e.what() << std::endl;
    }

    // Test 6: Creating a Bureaucrat with an invalid grade (too high, 0)
    std::cout << "\nRunning Test 6: Creating a Bureaucrat with an invalid grade "
		<< "(too high, 0)" << std::endl;
    try
    {
        Bureaucrat d("hello", 0);
        std::cout << d << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Test 6 failed: " << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Test 6 failed: " << e.what() << std::endl;
    }

    std::cout << GREEN << "\nAll tests completed." << RESET << std::endl;
    return 0;
}


