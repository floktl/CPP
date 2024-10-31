/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 08:42:55 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/31 09:00:40 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <cstdint>
#include <string>

struct Data
{
	int intVal;
	float floatVal;
	double doubleVal;
	std::string stringVal;
};

class Serializer
{
public:
	// Serialize: Convert a pointer to an unsigned integer type uintptr_t
	static uintptr_t serialize(Data* ptr);

	// Deserialize: Convert an unsigned integer back to a pointer of type Data*
	static Data* deserialize(uintptr_t raw);

private:
	//	make constructor pivate, so class cannot be instianted
	Serializer();
	Serializer(const Serializer &copy);
	~Serializer();
	Serializer &operator=(const Serializer &copy);
};

#endif