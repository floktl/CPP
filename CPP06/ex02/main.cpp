/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 08:39:37 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/31 09:47:10 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main() {
    // Test 1: Basic single object identification
    Base* obj = generate();

    std::cout << "\nUsing identify(Base*):" << std::endl;
    identify(obj);  // Identify using the pointer version

    std::cout << "\nUsing identify(Base&):" << std::endl;
    identify(*obj);  // Identify using the reference version

    delete obj;

    // Test 2: Multiple objects of different types
    Base* objA = new A();
    Base* objB = new B();
    Base* objC = new C();

    std::cout << "\nTesting identify on multiple objects:" << std::endl;
    identify(objA);  // Should identify as A
    identify(objB);  // Should identify as B
    identify(objC);  // Should identify as C

    delete objA;
    delete objB;
    delete objC;

    // Test 3: Repeated identification on the same object
    obj = generate();
    std::cout << "\nRepeated identification test:" << std::endl;
    identify(obj);
    identify(obj);  // Identify again to check consistency
    delete obj;

    // Test 4: Null pointer handling in identify(Base*)
    std::cout << "\nTesting identify with nullptr:" << std::endl;
    identify(nullptr);
	std::cout << std::endl;

    // Test 5: Edge case - identify after deletion
    std::cout << "\nTesting identify on deleted object (dangling pointer):" << std::endl;
    Base* danglingObj = generate();
    delete danglingObj;  // Delete the object to make the pointer dangling
    identify(danglingObj);  // May exhibit undefined behavior
	danglingObj = nullptr;
    identify(danglingObj);

    return 0;
}

