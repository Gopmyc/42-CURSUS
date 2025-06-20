#include "ex01.hpp"

int main()
{
	const std::string ADD 		=	"ADD";
	const std::string SEARCH	=	"SEARCH";
	const std::string EXIT		=	"EXIT";

	std::string sWord;
	PhoneBook Directory;

	Contact contact;
	unsigned int ADD_STATE	=	0;

	while (true)
	{
		if (ADD_STATE == 0)
		{
			if (!(std::cin >> sWord))
				break;

			if (sWord == ADD)
			{
				ADD_STATE = 1;
			}
			else if (sWord == SEARCH)
			{
				std::cout << "INDEX :" << std::endl;
			
				char c;
				if (!(std::cin >> c))
					break;
			
				if (c >= '0' && c <= '7')
				{
					byte index = c - '0';
					Directory.SearchContact(index);
				}
				else
				{
					std::cout << "Index invalide." << std::endl;
				}
			}
			else if (sWord == EXIT)
				break ;
		}
		else
		{
			std::cout << (ADD_STATE == 1 ? "FIRST NAME :" :
				ADD_STATE == 2 ? "LAST NAME :" :
				ADD_STATE == 3 ? "NICKNAME :" :
				ADD_STATE == 4 ? "PHONE NUMBER :" :
				"DARKEST SECRET :") << std::endl;

			if (!(std::cin >> sWord))
				break ;

			if (ADD_STATE == 1)
				contact.SetFirstName(sWord);
			else if (ADD_STATE == 2)
				contact.SetLastName(sWord);
			else if (ADD_STATE == 3)
				contact.SetNickName(sWord);
			else if (ADD_STATE == 4)
				contact.SetPhoneNumber(sWord);
			else if (ADD_STATE == 5)
			{
				contact.SetDarkestSecret(sWord);
				Directory.AddContact(contact);
			}

			if (ADD_STATE == 5)
				ADD_STATE = 0;
			else
				ADD_STATE++;
		}
	}
	return (0);
}
