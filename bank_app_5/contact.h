#pragma once
#include <string>
#include <iostream>

using std::string;
using std::ostream;

class Contact
{
private:
	string address;
	string city;
	string state;
	string zip;
	string phone;
public:
	Contact();
	void init_contact();
	ostream& get_info(ostream& output) const;
};

// Overload << operator
ostream& operator<< (ostream& output, Contact& contact);
