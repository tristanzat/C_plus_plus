// bank-app-3.cpp
#include "account.h"
#include <iostream>
#include <list>

static std::list<Account>::iterator find_account(std::list<Account>& accounts, int account_id)
{
    std::list<Account>::iterator it;
    for (it = accounts.begin(); it != accounts.end(); it++)
    {
        if ((*it).get_id() == account_id)
        {
            return it;
        }
    }

    return it;
}

int main()
{
    // Instantiate account list
    std::list<Account> accounts;

    // Initialize loop variables. Done, user choice, and whether or not an account has been made.
    bool done = false;
    int choice = 0;
    bool account_made = false;

    while (!done)
    {
        // Display menu
        std::cout << "\nAccount Menu:\n"
            "0. Quit Program\n"
            "1. Display Account Information\n"
            "2. Add a deposit to an account\n"
            "3. Withdraw from an account\n"
            "4. Add new account\n"
            "5. Find account by ID\n"
            "Your choice : ";

        // Get user choice and consume the newline
        std::cin >> choice;
        std::cin.ignore();

        // Allow switch to continue if an account exists, user is creating account, or user is trying to quit
        if (account_made || choice == 4 || choice == 0 || choice > 5)
        {

            // Handle user's choice
            switch (choice)
            {
                // Exit program
                case 0:
                    done = true;
                    break;

                // Display account information for all accounts
                case 1:
                    for (auto it_account = accounts.begin(); it_account != accounts.end(); it_account++)
                    {
                        std::cout << *it_account;
                    }
                    break;

                // Deposit money
                case 2:
                {
                    // Get id
                    std::cout << "Enter the ID of the account to find: ";
                    int search_id = 0;
                    std::cin >> search_id;

                    // Search and see if it was found
                    std::list<Account>::iterator it = find_account(accounts, search_id);

                    if (it != accounts.end())
                    {
                        std::cout << "Found account: " << (*it);
                        std::cout << "Amount to deposit: ";
                        float amount = 0;
                        std::cin >> amount;
                        (*it) += amount;
                    }
                    else
                    {
                        std::cout << "Account not found." << std::endl;
                    }
                    break;
                }
                // Withdraw money
                case 3:
                {
                    // Get id
                    std::cout << "Enter the ID of the account to find: ";
                    int search_id = 0;
                    std::cin >> search_id;

                    // Search and see if it was found
                    std::list<Account>::iterator it = find_account(accounts, search_id);

                    if (it != accounts.end())
                    {
                        std::cout << "Found account: " << (*it);
                        std::cout << "Amount to withdraw: ";
                        float amount = 0;
                        std::cin >> amount;
                        (*it) -= amount;
                    }
                    else
                    {
                        std::cout << "Account not found." << std::endl;
                    }
                    break;
                }
                // Add new account
                case 4:
                {
                    Account account;
                    account.init_account();
                    accounts.push_back(account);
                    account_made = true;
                    break;
                }
                // Find account by id
                case 5:
                {
                    // Get id
                    std::cout << "Enter the ID of the account to find: ";
                    int search_id = 0;
                    std::cin >> search_id;

                    // Search and see if it was found
                    std::list<Account>::iterator it = find_account(accounts, search_id);

                    if (it != accounts.end())
                    {
                        std::cout << "Found account: " << (*it);
                    }
                    else
                    {
                        std::cout << "Account not found." << std::endl;
                    }
                    break;
                }
                // Default: quit
                default:
                    done = true;
                    break;
            }
        }

        // User is trying to call a function without an account. Display error
        else
        {
            std::cout << "Error: No accounts exist. Create an account to continue." << std::endl;
        }
    }

    return 0;
}