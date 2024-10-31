/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 08:39:37 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/31 09:48:24 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	//	Test 1: Basic Serialization and Deserialization of a Single Object
	Data data1 = {1, 42.0f, 84.25, "Test 1"};
	uintptr_t serializedData1 = Serializer::serialize(&data1);
	Data* deserializedData1 = Serializer::deserialize(serializedData1);
	std::cout << "Test 1 - Serialized value: " << serializedData1 << std::endl;
	std::cout << "Deserialized pointer matches original: "
			<< (deserializedData1 == &data1 ? "Yes" : "No") << std::endl;

	//	Display deserialized values for verification
	std::cout << "Deserialized Data1 - intVal: " << deserializedData1->intVal
			<< ", floatVal: " << deserializedData1->floatVal
			<< ", doubleVal: " << deserializedData1->doubleVal
			<< ", stringVal: " << deserializedData1->stringVal << std::endl;

	//	Test 2: Serialization and Deserialization of Multiple Objects
	Data data2 = {2, 84.5f, 168.75, "Test 2"};
	Data data3 = {3, 126.75f, 253.125, "Test 3"};

	uintptr_t serializedData2 = Serializer::serialize(&data2);
	uintptr_t serializedData3 = Serializer::serialize(&data3);

	Data* deserializedData2 = Serializer::deserialize(serializedData2);
	Data* deserializedData3 = Serializer::deserialize(serializedData3);

	std::cout << "\nTest 2 - Multiple Objects" << std::endl;
	std::cout << "Data2 - Serialized: " << serializedData2
			<< ", Matches original: "
				<< (deserializedData2 == &data2 ? "Yes" : "No") << std::endl;
	std::cout << "Deserialized Data2 - intVal: " << deserializedData2->intVal
			<< ", floatVal: " << deserializedData2->floatVal
			<< ", doubleVal: " << deserializedData2->doubleVal
			<< ", stringVal: " << deserializedData2->stringVal << std::endl;

	std::cout << "Data3 - Serialized: " << serializedData3
			<< ", Matches original: "
			<< (deserializedData3 == &data3 ? "Yes" : "No") << std::endl;
	std::cout << "Deserialized Data3 - intVal: " << deserializedData3->intVal
			<< ", floatVal: " << deserializedData3->floatVal
			<< ", doubleVal: " << deserializedData3->doubleVal
			<< ", stringVal: " << deserializedData3->stringVal << std::endl;

	//	Test 3: Null Pointer Serialization and Deserialization
	Data* nullData = nullptr;
	uintptr_t serializedNull = Serializer::serialize(nullData);
	Data* deserializedNull = Serializer::deserialize(serializedNull);

	std::cout << "\nTest 3 - Null Pointer" << std::endl;
	std::cout << "Serialized Null Pointer: " << serializedNull << std::endl;
	std::cout << "Deserialized pointer is null: "
			<< (deserializedNull == nullptr ? "Yes" : "No") << std::endl;

	//	Test 4: Check If Deserialized Pointer Points to the Correct Object
	//	(Memory Address Verification)
	std::cout << "\nTest 4 - Memory Address Verification" << std::endl;
	std::cout << "Original address of Data1: " << &data1 << std::endl;
	std::cout << "Deserialized address of Data1: " << deserializedData1
		<< std::endl;
	std::cout << "Original address of Data2: " << &data2 << std::endl;
	std::cout << "Deserialized address of Data2: " << deserializedData2
		<< std::endl;
	std::cout << "Original address of Data3: " << &data3 << std::endl;
	std::cout << "Deserialized address of Data3: " << deserializedData3
		<< std::endl;

	return 0;
}
