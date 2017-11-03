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
		neg(								// 0 - ( ( (5-4) * (8/2) ) + 7)
			add(							//	( ( (5-4) * (8/2) ) + 7
				mul(						//	(5-4) * (8/2)
					sub(5, 4),				//	(5-4)
					zmath::div(8, 2))		//	(8/2)
				, 7)						//	the + 7 from the end of the comment on line 41
		) << std::endl;


	std::cin.get();		//Hold the window
	return 0;
}