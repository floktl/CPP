/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:25:37 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/27 09:43:37 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	Cat::type = "Cat";
	std::cout << "Cat has been created!" << std::endl;
}

Cat::~Cat()
{
	Cat::type = "Cat";
	std::cout << "Cat has been brutally slaughtered!" << std::endl;
}

Cat::Cat(const Cat &other) :Animal(other)
{
	Cat::type = other.type;
}

void Cat::makeSound() const
{
	std::cout << "Miauuuuu!" << std::endl;
}