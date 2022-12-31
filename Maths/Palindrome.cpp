#include <iostream>

bool palindrom_number(size_t number)
{
	size_t number1 = number;
	size_t sum = 0;
	for (; number; number = number / 10)
	{
		sum = (sum * 10) + (number % 10);
	}
	return(number1 == sum);
}

int main()
{
	std::cout << "value : " << palindrom_number(233) << "\n";
}
