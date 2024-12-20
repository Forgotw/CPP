#include <iostream>
#include <Array.hpp>

#define MAX_VAL 15
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
		std::cout << "numbers[" << i << "]= " << numbers[i] << std::endl;
		std::cout << "mirror[" << i << "]= " << mirror[i] << std::endl;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
		std::cout << std::endl;
		for (int i = 0; i < MAX_VAL; i++) {
			std::cout << "tmp[" << i << "]= " << tmp[i] << std::endl;
			std::cout << "test[" << i << "]= " << test[i] << std::endl;
			if (mirror[i] != numbers[i])
            	std::cerr << "didn't save the same value!!" << std::endl;
		}
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
	std::cout << std::endl;
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

	std::cout << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
		std::cout << "numbers[" << i << "]= " << numbers[i] << std::endl;
		std::cout << "mirror[" << i << "]= " << mirror[i] << std::endl;
        if (mirror[i] != numbers[i])
            std::cerr << "didn't save the same value!!" << std::endl;
    }
    delete [] mirror;//
    return 0;
}
