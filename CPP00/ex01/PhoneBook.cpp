#include "ex01.hpp"

PhoneBook::PhoneBook() : _nextIndex(0)	{}

PhoneBook::~PhoneBook()					{}

void PhoneBook::AddContact(Contact contact)
{
	_Contacts[_nextIndex]	=	contact;
	_nextIndex				=	(_nextIndex + 1) % 8;
}

std::string FormatField(const std::string& str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return std::string(10 - str.length(), ' ') + str;
}

void PhoneBook::SearchContact(byte index)
{
	if (_Contacts[index].IsValid())
	{
		std::cout << "         " << static_cast<int>(index) << " | "
			<< FormatField(_Contacts[index].GetFirstName()) << " | "
			<< FormatField(_Contacts[index].GetLastName()) << " | "
			<< FormatField(_Contacts[index].GetNickName()) << std::endl;
	}
	else
		std::cout << "Aucun contact à cet index." << std::endl;
}
