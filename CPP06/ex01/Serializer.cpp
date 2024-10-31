/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 08:53:39 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/31 08:56:33 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &other)
{
	*this = other;
}

Serializer::~Serializer()
{
}

Serializer &Serializer::operator=(const Serializer &other)
{
	if (this != &other)
		*this = other;
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	//	casting a Data* pointer to uintptr_t just changes the type of
	//	the pointer, not the memory it points to
	return (reinterpret_cast<Data*>(raw));
}