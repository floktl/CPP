/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 08:53:39 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/31 09:31:24 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

// Function to randomly instantiate A, B, or C and return as Base*
Base* generate()
{
	//	Initialize the random number generator in C++ with a "seed" value
	//	different seeds (like the current time)
	//	you get different random sequences
    std::srand(std::time(nullptr));
	//	without s rand, the seed is always the same
    int random = std::rand() % 3;

    if (random == 0)
	{
        std::cout << "Generated type: A" << std::endl;
        return new A();
    }
	else if (random == 1)
	{
        std::cout << "Generated type: B" << std::endl;
        return new B();
    }
	else
	{
        std::cout << "Generated type: C" << std::endl;
        return new C();
    }
}

// Identify function for Base* pointer
void identify(Base* p)
{
	//	dynamic_cast performs a runtime check to see if the type conversion is valid
	//	If the cast fails: When using a pointer, it returns nullptr.
    if (dynamic_cast<A*>(p))
        std::cout << "Type identified: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Type identified: B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Type identified: C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

// Identify function for Base& reference
void identify(Base& p)
{
    try
	{
		//	If the cast to Class A fails: When using a reference
		//	it throws a std::bad_cast exception.
        (void)dynamic_cast<A&>(p);
        std::cout << "Type identified: A" << std::endl;
    }
	catch (const std::bad_cast&)
	{
		//	continue with class b
        try
		{
            (void)dynamic_cast<B&>(p);  // Attempt dynamic cast to B
            std::cout << "Type identified: B" << std::endl;
        }
		catch (const std::bad_cast&)
		{
			//	last try for class C
            try
			{
                (void)dynamic_cast<C&>(p);  // Attempt dynamic cast to C
                std::cout << "Type identified: C" << std::endl;
            }
			catch (const std::bad_cast&)
			{
                std::cout << "Unknown type" << std::endl;
            }
        }
    }
}
