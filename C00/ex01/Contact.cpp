#include "ex01.hpp"

Contact::Contact() {}
Contact::~Contact() {}

void Contact::SetFirstName(std::string sFirstName)			{ _FirstName = sFirstName; }
void Contact::SetLastName(std::string sLastName)			{ _LastName = sLastName; }
void Contact::SetNickName(std::string sNickName)			{ _NickName = sNickName; }
void Contact::SetPhoneNumber(std::string sPhoneNumber)		{ _PhoneNumber = sPhoneNumber; }
void Contact::SetDarkestSecret(std::string sDarkestSecret)	{ _DarkestSecret = sDarkestSecret; }

bool Contact::IsValid() const								{ return !_FirstName.empty();}

const std::string& Contact::GetFirstName() const			{ return _FirstName; }
const std::string& Contact::GetLastName() const				{ return _LastName; }
const std::string& Contact::GetNickName() const				{ return _NickName; }
const std::string& Contact::GetPhoneNumber() const			{ return _PhoneNumber; }
const std::string& Contact::GetDarkestSecret() const		{ return _DarkestSecret; }