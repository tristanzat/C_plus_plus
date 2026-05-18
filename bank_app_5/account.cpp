#include "account.h"
#include "contact.h"
#include <iostream>
#include <format>
#include <memory>

// Define static member
int Account::next_free_id = 0;

// Base constructor; initialize to empty
Account::Account() : account_id{ 0 }, name{ "" }, balance{ 0 }, contact_info{ nullptr } {}

// Initialize account by setting account id then asking for user input
void Account::init_account() {
	// Set account ID and increase it for next
	account_id = next_free_id;
	next_free_id++;

	// Get name
	std::cout << "Enter the name: ";
	std::getline(std::cin, name);

	// Get balance
	std::cout << "Enter the balance: ";

	bool valid = false;

	while (!valid)
	{
		// Validate input
		if (!(std::cin >> balance))
		{
			std::cin.clear(); // Reset the error flags
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard bad input
			std::cout << "Inavlid balance. Please enter a decimal value: ";
		}
		else
		{
			valid = true;
		}
	}
}

// Assign contact info
void Account::add_contact() {
	contact_info = std::make_shared<Contact>();
	contact_info->init_contact();
}

// Return id
int Account::get_id() const {
	return account_id;
}

// Return balance
float Account::get_balance() const {
	return balance;
}

// Increase balance by amount
void Account::deposit(float amount) {
	balance += amount;
}

// Overload += operator for depositing
Account& Account::operator+=(float amount) {
	balance += amount;
	return *this;
}

// Decrease balance by amount
void Account::withdraw(float amount) {
	balance -= amount;
}

// Overload -= operator for withdrawal
Account& Account::operator-=(float amount) {
	balance -= amount;
	return *this;
}

// Display account information
void Account::display() {
	std::cout << "Account ID: " << account_id << "  Name: " << name << "  Balance: $" << std::format("{:.2f}", balance) << std::endl;
}

// Alternative display for flexible output stream
std::ostream& Account::display(std::ostream& output) const {
	output << "Account ID: " << account_id << "  Name: " << name << "  Balance: $" << std::format("{:.2f}", balance);
	if (contact_info) {
		output << "\n+ Contact Information: ";
		contact_info->get_info(output);
	}
	return output;
}

// Overload << operator
std::ostream& operator<< (std::ostream& output, Account& account) {
	return account.display(output);
}
