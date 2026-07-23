#include "Serializer.hpp"

int main(void) {
	
	Data myData;

	myData.num = 42; myData.str = "Malaga";
	std::cout << "--------" << &myData << "-------" << std::endl;
	std::cout << "Number from data: " << myData.num << std::endl;
	std::cout << "String from data: " << myData.str << std::endl;
	std::cout << "****************************************" << std::endl;
	uintptr_t raw = Serializer::serialize(&myData);
	std::cout << "Pointer serialized: " << raw << std::endl;
	std::cout << "****************************************" << std::endl;
	Data* dataDeserialize = Serializer::deserialize(raw);
	std::cout << "--------" << dataDeserialize << "-------" << std::endl;
	std::cout << "Number from data: " << dataDeserialize->num << std::endl;
	std::cout << "String from data: " << dataDeserialize->str << std::endl;
	std::cout << "********************" << std::endl;

	return 0;
}