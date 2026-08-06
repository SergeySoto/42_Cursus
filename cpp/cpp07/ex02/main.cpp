#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
	
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
	std::cout << numbers[0] << std::endl;
	Array<int> empty;
	std::cout << "size of empty: " << empty.size() << std::endl;
	try {
		std::cout << "value of empty[0]: " << empty[0] << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	Array<int> array1(5);
	Array<int> array2(10);
	array1 = array2;
	std::cout << "size of array1: " << array1.size() << std::endl;
	std::cout << "size of array2: " << array2.size() << std::endl;
	Array<std::string> words(3);
	words[0] = "Hola"; words[1] = "42"; words[2] = "Malaga";
	for (int i = 0; i < 3; ++i)
		std::cout << words[i] << std::endl;
	const Array<int> constArray(numbers);
	std::cout << constArray[0] << std::endl;
	// constArray[0] = 42;
    delete [] mirror;
    return 0;
}