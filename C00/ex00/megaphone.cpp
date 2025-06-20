#include <iostream>
#include <string>

#ifndef EXIT_SUCCESS
# define EXIT_SUCCESS 0
#endif
#ifndef EXIT_FAILURE
# define EXIT_FAILURE 1
#endif

int main(int ac, char **av)
{
	int i = 1;

	if (ac <= 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, EXIT_SUCCESS);
	while (i < ac)
	{
		std::string s = av[i];
		for (size_t j = 0; j < s.size(); ++j)
			std::cout << static_cast<char>(std::toupper(s[j]));
		i++;	
	}
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}