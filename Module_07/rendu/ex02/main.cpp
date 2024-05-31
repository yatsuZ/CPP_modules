#include <iostream>
#include <cstdlib>
#include "./Array/Array.hpp"

void test_00(void)
{
	Array<int>	t(3);
	Array<int>	t2;

	try
	{
		t[50] = 5;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	t[0] = 5;
	std::cout << "---------------------" << std::endl;
	iter(t.getTab(), t.size(), Show);
	t2 = t;
	t[0] = -3;
	std::cout << "---------------------" << std::endl;
	iter(t.getTab(), t.size(), Show);
	std::cout << "---------------------" << std::endl;
	iter(t2.getTab(), t2.size(), Show);
}

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
	iter(numbers.getTab(), 3, Show);
	std::cout << "---------------------" << std::endl;
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
		iter(tmp.getTab(), 3, Show);
		std::cout << "---------------------" << std::endl;
		iter(test.getTab(), 3, Show);
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
    delete [] mirror;//
    return 0;
}