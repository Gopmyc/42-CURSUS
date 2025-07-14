#include <iostream>
#include <string>

int main()
{
	std::string	sStr = "HI THIS IS BRAIN";
	std::string*	psStr = &sStr;
	std::string&	rsStr = sStr;

	std::cout << &sStr << std::endl;
	std::cout << psStr << std::endl;
	std::cout << &rsStr << std::endl;

	std::cout << sStr << std::endl;
	std::cout << *psStr << std::endl;
	std::cout << rsStr << std::endl;

	return (0);
}
