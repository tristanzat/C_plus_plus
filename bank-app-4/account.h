#pragma once
#include <string>
#include <format>
#include <iostream>

class Account
{
private:
	int account_id;
	std::string name;
	float balance;
	static int next_free_id;
public:
	Account();
	void init_account();
	void display();
	void deposit(float amount);
	void withdraw(float amount);
	float get_balance();
	int get_id();
	Account& operator+= (float amount);
	Account& operator-= (float amount);
	std::ostream& display(std::ostream& output) const;
};

// Overload << operator
std::ostream& operator<< (std::ostream& output, Account& account);
