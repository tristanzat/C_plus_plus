#include "contact.h"
#include <iostream>

using std::cout, std::cin, std::getline;

// Base constructor; initialize to empty
Contact::Contact() : address{ "" }, city{ "" }, state{ "" }, zip{ "" }, phone{ "" } {}

// Get info to put in variables
void Contact::init_contact() {
	
	cout << "Enter Address : ";
	getline(cin, address);

	cout << "Enter City : ";
	getline(cin, city);

	cout << "Enter State : ";
	getline(cin, state);

	cout << "Enter Zip Code : ";
	getline(cin, zip);

	cout << "Enter Phone Number : ";
	getline(cin, phone);
}

// Return ostream for display
std::ostream& Contact::get_info(std::ostream& output) const {
	return output << "Address: " << address << " City: " << city << " State: " << state << " Zip: " << zip << " Phone: " << phone;
}

// Overload << operator
std::ostream& operator<< (std::ostream& output, Contact& contact) {
	return contact.get_info(output);
}