#include "account.h"
#include <iostream>
#include <format>

// Define static member
int Account::next_free_id = 0;

// Empty constructor; initialize to empty
Account::Account() : account_id{ 0 }, name{ "" }, balance{ 0 } {}

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
	std::cin >> balance;
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
	return output << "Account ID: " << account_id << "  Name: " << name << "  Balance: $" << std::format("{:.2f}", balance) << std::endl;
}

// Overload << operator
std::ostream& operator<< (std::ostream& output, Account& account) {
	return account.display(output);
}
