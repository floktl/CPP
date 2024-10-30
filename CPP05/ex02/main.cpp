/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:16:29 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/30 09:12:04 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// ANSI color codes for output styling
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define PURPLE  "\033[35m"

int main()
{
    try
    {
        // Create Bureaucrats with different grades
        Bureaucrat alice("Alice", 140);
        Bureaucrat bob("Bob", 150);
        Bureaucrat charlie("Charlie", 130);
        Bureaucrat dave("Dave", 50);
        Bureaucrat eve("Eve", 10);

        Bureaucrat* bureaucrats[] = { &bob, &alice, &charlie, &dave, &alice, &dave, &charlie, &dave, &eve, &dave, &eve, &eve};
        std::string actions[] = { "sign", "sign", "execute", "sign", "sign", "execute", "execute", "sign", "sign", "execute", "execute" , "execute"};
        std::string formTypes[] = { "ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm" };
        std::string targets[] = { "Garden", "TargetA", "TargetB" };

        // Loop through each test
        for (int i = 0; i < 12; ++i)
        {
            std::cout << BLUE << "\nTest " << i + 1 << ": " << actions[i] << " "
				<< PURPLE << formTypes[i % 3] << RESET
				<< " for target " << targets[i % 3] << " with "
				<< YELLOW << bureaucrats[i]->getName() << RESET
				<< " (Grade " << bureaucrats[i]->getGrade() << ")"
				<< RESET << std::endl;

            AForm* form = nullptr;

            // Initialize the correct form type
            if (formTypes[i % 3] == "ShrubberyCreationForm")
                form = new ShrubberyCreationForm(targets[i % 3]);
            else if (formTypes[i % 3] == "RobotomyRequestForm")
                form = new RobotomyRequestForm(targets[i % 3]);
            else if (formTypes[i % 3] == "PresidentialPardonForm")
                form = new PresidentialPardonForm(targets[i % 3]);

			form->print(std::cout);
            try
            {
                // Perform the action based on the test setup

                if (actions[i] == "sign" && form)
                {
                    std::cout << YELLOW << "Attempting to sign..." << RESET << std::endl;
                    bureaucrats[i]->signForm(*form);
                }
                else if (actions[i] == "execute" && form)
                {
                    std::cout << YELLOW << "Attempting to execute..." << RESET << std::endl;
                    bureaucrats[i]->executeForm(*form);
					bureaucrats[i]->signForm(*form);
                    bureaucrats[i]->executeForm(*form);
                }
                std::cout << GREEN << "Action completed successfully.\n" << RESET << std::endl;
            }
            catch (const std::exception& e)
            {
                std::cerr << RED << "Exception occurred: " << e.what() << RESET << '\n';
            }

            delete form; // Clean up the form
        }

        std::cout << GREEN << "\nAll tests completed." << RESET << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << RED << "An error occurred: " << e.what() << RESET << std::endl;
    }
    return 0;
}
