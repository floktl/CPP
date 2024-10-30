/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:16:22 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/30 09:46:46 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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
        // Bureaucrats and their initial actions
        struct BureaucratTest
        {
            std::string name;
            int initialGr;
            int gradeChange;
            bool isIncrease;
        };

        BureaucratTest bureaucratTests[] = {
            { "John", 50, 10, true },
            { "John", 40, 20, false },
            { "Alice", 25, 0, true } // No grade change, just creation
        };

        // Run Bureaucrat tests
        Bureaucrat* john = nullptr;
        for (int i = 0; i < 3; ++i)
        {
            BureaucratTest test = bureaucratTests[i];
            std::cout << BLUE << "\nTest " << i + 1
				<< ": \nCreating Bureaucrat '" << test.name << "' with Grade "
				<< test.initialGr << RESET << std::endl;

            Bureaucrat* bureaucrat = new Bureaucrat(test.name, test.initialGr);
            std::cout << YELLOW << *bureaucrat << RESET << std::endl;

            if (test.gradeChange != 0)
            {
                std::cout << BLUE
					<< (test.isIncrease ? "\nIncreasing " : "\nDecreasing ")
                	<< test.name << "'s grade by " << test.gradeChange
					<< RESET << std::endl;
                try
                {
                    if (test.isIncrease)
                        bureaucrat->incGrade(test.gradeChange);
                    else
                        bureaucrat->decGrade(test.gradeChange);

                    std::cout << GREEN << "After grade adjustment: "
						<< YELLOW << *bureaucrat << RESET << std::endl;
                }
                catch (std::exception& e)
                {
                    std::cerr << RED << "Exception: " << e.what()
						<< RESET << std::endl;
                }
            }

            if (test.name == "John")
                john = bureaucrat; // Save John for later form signing
            else
                delete bureaucrat; // Clean up unless it's saved
        }

        // Create forms and attempt signing
        struct FormTest
        {
            std::string name;
            int signGrade;
            int execGrade;
            std::string bureaucratName;
        };

        FormTest formTests[] = {
            { "Tax Form", 30, 20, "John" },
            { "Tax Form", 30, 20, "Alice" },
            { "Invalid Form", 0, 20, "N/A" } // Invalid form creation test
        };

        for (int i = 0; i < 3; ++i)
        {
            FormTest test = formTests[i];
            if (test.signGrade <= 0 || test.signGrade > 150)
            {
                // Invalid form test
                std::cout << BLUE << "\nTest " << i + 4
					<< ": Attempting to create invalid form '"
                    << test.name << "' with sign grade " << test.signGrade
					<< RESET << std::endl;
                try
                {
                    Form invalidForm(test.name, test.signGrade, test.execGrade);
                }
                catch (std::exception& e)
                {
                    std::cerr << RED << "Error creating form: " << e.what()
						<< RESET << std::endl;
                }
            }
            else
            {
                // Valid form creation and signing attempt
                std::cout << BLUE << "\nTest " << i + 4 << ": Creating form '"
                    << test.name << RESET << std::endl;

                Form form(test.name, test.signGrade, test.execGrade);
                std::cout << PURPLE << form << RESET << std::endl;

                Bureaucrat* signer = (test.bureaucratName == "John")
					? john : new Bureaucrat("Alice", 25);
                std::cout << BLUE << "\n" << signer->getName()
					<< " attempts to sign " << test.name << RESET << std::endl;

                signer->signForm(form);
                std::cout << PURPLE << form << RESET << std::endl;

                // Addit. test: Attempt to sign the already signed form again
                std::cout << BLUE
					<< "\nAttempting to sign an already signed form '"
					<< test.name << "' with " << signer->getName()
					<< RESET << std::endl;

                try
                {
					form.print(std::cout);
                    signer->signForm(form);
                }
                catch (std::exception& e)
                {
                    std::cerr << RED << "Exception: " << e.what()
						<< RESET << std::endl;
                }

                if (signer->getName() == "Alice") delete signer;
            }
        }

        // Invalid Bureaucrat test
        std::cout << BLUE << "\nTest 7: Create Bureaucrat with Grade out of range"
			<< RESET << std::endl;
        try
        {
            Bureaucrat invalidBureaucrat("Invalid Bureaucrat", 151);
        }
        catch (std::exception& e)
        {
            std::cerr << RED << "Error creating bureaucrat: " << e.what() << RESET << std::endl;
        }

        // Clean up saved instance
        delete john;

    }
    catch (std::exception& e)
    {
        std::cerr << RED << "General exception: " << e.what() << RESET << std::endl;
    }

    std::cout << GREEN << "\nAll tests completed." << RESET << std::endl;
    return 0;
}
