#include <iostream>

//The namespace is here to resolve a name conflict between my div function and a function with the same name in stdlib.h
namespace zmath
{
	//Adds first and second
	int add(int first, int second)
	{
		return first + second;
	}

	//Subtracts second from first
	int sub(int first, int second)
	{
		return first - second;
	}

	//Multiplies first by second
	int mul(int first, int second)
	{
		return first * second;
	}

	//Divides first by second
	int div(int first, int second)
	{
		return first / second;
	}

	//Raises value to power
	int pow(int value, int power)
	{
		int ret = 1;
		for (int i = power; i > 0; i--)
		{
			ret = mul(ret, value);
		}
		return ret;
	}

	//Returns the factorial of value
	int fac(int value)
	{
		int ret = 1;
		for (int i = value; i > 1; i--)
		{
			ret = mul(ret, i);
		}
		return ret;
	}

	//Negates value
	int neg(int value)
	{
		return mul(value, -1);
	}
};

int main()
{
	using namespace zmath;	//Used to clear up a name conflict (see above)
	std::cout << "Result: " << 
		pow(
			add( fac(5), fac(4))
			, 3)
		<< std::endl;


	std::cin.get();		//Hold the window
	return 0;
}