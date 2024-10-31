/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 08:42:55 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/31 09:32:34 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

// Base class with a public virtual destructor
class Base
{
public:
    virtual ~Base() {}
};

Base* generate();
void identify(Base* p);
void identify(Base& p);

// Classes A, B, and C that inherit from Base
class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif