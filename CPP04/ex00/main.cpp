/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:03:37 by flo               #+#    #+#             */
/*   Updated: 2024/10/27 09:27:33 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
int main() {
    const Animal* animals[2];
    const WrongAnimal* wrongAnimals[2];

    animals[0] = new Dog();
    animals[1] = new Cat();
    wrongAnimals[0] = new WrongAnimal();
    wrongAnimals[1] = new WrongCat();

    // Tests
    std::cout << "Testing Animal types and sounds:" << std::endl;
    for (int i = 0; i < 2; ++i) {
        std::cout << "Animal " << i + 1 << " is a " << animals[i]->getType() << std::endl;
        animals[i]->makeSound();
    }
    std::cout << "\nTesting WrongAnimal types and sounds:" << std::endl;
    for (int i = 0; i < 2; ++i) {
        std::cout << "WrongAnimal " << i + 1 << " is a " << wrongAnimals[i]->getType() << std::endl;
        wrongAnimals[i]->makeSound();
    }

    for (int i = 0; i < 2; ++i) {
        delete animals[i];
        delete wrongAnimals[i];
    }

    std::cout << "\nSingle object tests:" << std::endl;
    const Animal* singleDog = new Dog();
    const WrongAnimal* singleWrongCat = new WrongCat();

    std::cout << "Single Dog type: " << singleDog->getType() << std::endl;
    singleDog->makeSound();
    std::cout << "Single WrongCat type: " << singleWrongCat->getType() << std::endl;
    singleWrongCat->makeSound();
    delete singleDog;
    delete singleWrongCat;
    return 0;
}

