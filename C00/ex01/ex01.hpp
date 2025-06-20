#ifndef EX01_HPP
#define EX01_HPP

#include <iostream>
#include <string>

typedef unsigned char byte;

class Contact
{
	public:
		Contact();
		~Contact();
	
		void SetFirstName(std::string s);
		void SetLastName(std::string s);
		void SetNickName(std::string s);
		void SetPhoneNumber(std::string s);
		void SetDarkestSecret(std::string s);
	
		bool IsValid() const;
		const std::string& GetFirstName() const;
		const std::string& GetLastName() const;
		const std::string& GetNickName() const;
		const std::string& GetPhoneNumber() const;
		const std::string& GetDarkestSecret() const;
	
	private:
		std::string _FirstName;
		std::string _LastName;
		std::string _NickName;
		std::string _PhoneNumber;
		std::string _DarkestSecret;
};

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();

		void AddContact(Contact contact);
		void SearchContact(byte index);

	private:
		Contact _Contacts[8];
		byte _nextIndex;
};

#endif
