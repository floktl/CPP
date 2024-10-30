/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:16:29 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/30 07:16:47 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;
    Bureaucrat burro("Burro", 1);

    std::string formNames[] = {"shrubbery creation", "robotomy request",
		"presidential pardon", "nonexistent form"};
    std::string targets[] = {"Garden", "TargetA", "TargetB", "SomeTarget"};

    for (int i = 0; i < 4; ++i)
    {
        try
        {
			std::cout << "\nTEST " << i + 1 << "\n" << std::endl;
			//	Inter creates Form
            std::cout << BLUE << "\nIntern makes Form: " << YELLOW << formNames[i]
				<< BLUE << " for target " << targets[i] << "\n" << RESET
				<< std::endl;

            AForm* form = someRandomIntern.makeForm(formNames[i], targets[i]);

			// 	testing functions of each form
			std::cout << GREEN << "\nTesting valid Form: " << formNames[i]
				<< "\n" << RESET << std::endl;
			burro.signForm(*form);
			burro.executeForm(*form);
			delete form;
        }
        catch (const std::exception& e)
        {
            std::cerr << RED << "\nException occurred: " << e.what() << RESET
				<< std::endl;;
        }
    }

    return 0;
}


