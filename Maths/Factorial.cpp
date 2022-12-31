#include <iostream>

int factorial(int number)
{
	int sum = 1;
	for (int i = 2; i <= number; ++i)
	{
		sum *= i;
	}
	return sum;
}

int fac_rec(int number)
{
	if (number == 0)
		return 1;
	return number * fac_rec(number - 1);
}

int main()
{
	std::cout << "fac : " << fac_rec(5) << "\n";
}
