// bank-app-4.cpp
#include "account.h"
#include <iostream>
#include <list>
#include <algorithm>
#include <numeric>
#include <limits>
#include <tuple>

static std::list<Account>::iterator find_account(std::list<Account>& accounts, int account_id);
template<typename T>
static std::tuple<bool, T> valid_input(std::istream& input);

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
        // Initialize choice for loop
        bool valid_choice = false;

        // Display menu
        std::cout << "\nAccount Menu:\n"
            "0. Quit Program\n"
            "1. Display Account Information\n"
            "2. Add a deposit to an account\n"
            "3. Withdraw from an account\n"
            "4. Add new account\n"
            "5. Find account by ID\n"
            "6. Remove account\n"
            "7. Show total balance for all accounts\n"
            "8. Add a dividend to all accounts\n"
            "Your choice : ";

        // Validate user choice
        while (!valid_choice)
        {
            auto valid = valid_input<int>(std::cin);
            valid_choice = std::get<0>(valid);

            if (valid_choice)
            {
                choice = std::get<1>(valid);
            }
            else
            {
                std::cout << "Invalid input. Please enter a valid option (0-8): ";
            }
        }

        // Consume newline
        std::cin.ignore();

        // Allow switch to continue if an account exists, user is creating account, or user is trying to quit
        if (account_made || choice == 4 || !(1 <= choice && choice <= 8))
        {

            // Handle user's choice
            switch (choice)
            {
                // Display account information for all accounts
                case 1:
                    for_each(accounts.begin(), accounts.end(), [](auto account){
                        std::cout << account;
                        });
                    break;

                // Deposit money
                case 2:
                {
                    // Get id
                    std::cout << "Enter the ID of the account to find: ";
                    int search_id = 0;
                    
                    bool valid = false;
                    // Validate user choice
                    while (!valid)
                    {
                        auto valid_tuple = valid_input<int>(std::cin);
                        valid = std::get<0>(valid_tuple);

                        if (valid)
                        {
                            search_id = std::get<1>(valid_tuple);
                        }
                        else
                        {
                            std::cout << "Invalid input. Please enter a valid option (non-negative integer): ";
                        }
                    }

                    // Search and see if it was found
                    std::list<Account>::iterator it = find_account(accounts, search_id);

                    if (it != accounts.end())
                    {
                        std::cout << "Found account: " << (*it);
                        std::cout << "Amount to deposit: ";
                        float amount = 0;

                        // Validate user choice
                        bool valid = false;
                        while (!valid)
                        {
                            auto valid_tuple = valid_input<float>(std::cin);
                            valid = std::get<0>(valid_tuple);

                            if (valid)
                            {
                                amount = std::get<1>(valid_tuple);
                                if (amount <= 0)
                                {
                                    valid = false;
                                }
                            }
                            if (!valid)
                            {
                                std::cout << "Invalid input. Please enter a positive, non-zero decimal number: ";
                            }
                        }

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

                    // Validate user choice
                    bool valid = false;
                    while (!valid)
                    {
                        auto valid_tuple = valid_input<int>(std::cin);
                        valid = std::get<0>(valid_tuple);

                        if (valid)
                        {
                            search_id = std::get<1>(valid_tuple);
                        }
                        else
                        {
                            std::cout << "Invalid input. Please enter a valid option (non-negative integer): ";
                        }
                    }

                    // Search and see if it was found
                    std::list<Account>::iterator it = find_account(accounts, search_id);

                    if (it != accounts.end())
                    {
                        std::cout << "Found account: " << (*it);
                        std::cout << "Amount to withdraw: ";
                        float amount = 0;

                        // Validate user choice
                        bool valid = false;
                        while (!valid)
                        {
                            auto valid_tuple = valid_input<float>(std::cin);
                            valid = std::get<0>(valid_tuple);

                            if (valid)
                            {
                                amount = std::get<1>(valid_tuple);
                                if (amount <= 0)
                                {
                                    valid = false;
                                }
                            }
                            if (!valid)
                            {
                                std::cout << "Invalid input. Please enter a positive, non-zero decimal number: ";
                            }
                        }

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
                    
                    // Validate user choice
                    bool valid = false;
                    while (!valid)
                    {
                        auto valid_tuple = valid_input<int>(std::cin);
                        valid = std::get<0>(valid_tuple);

                        if (valid)
                        {
                            search_id = std::get<1>(valid_tuple);
                        }
                        else
                        {
                            std::cout << "Invalid input. Please enter a valid option (non-negative integer): ";
                        }
                    }

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
                // Remove account
                case 6:
                {
                    // Get id
                    std::cout << "Enter ID of account to remove: ";
                    int remove_id = 0;
                    
                    // Validate user choice
                    bool valid = false;
                    while (!valid)
                    {
                        auto valid_tuple = valid_input<int>(std::cin);
                        valid = std::get<0>(valid_tuple);

                        if (valid)
                        {
                            remove_id = std::get<1>(valid_tuple);
                        }
                        else
                        {
                            std::cout << "Invalid input. Please enter a valid option (non-negative integer): ";
                        }
                    }

                    // Use remove_if to see if account exists to be removed
                    auto accounts_end = remove_if(accounts.begin(), accounts.end(), [remove_id](auto account) {
                        return account.get_id() == remove_id;
                        });

                    // Use erase to remove account
                    accounts.erase(accounts_end, accounts.end());

                    // Don't allow account operations to be performed if no account exists
                    if (accounts.size() <= 0)
                    {
                        account_made = false;
                    }
                    break;
                }
                // Show total balance
                case 7:
                {
                    // Add up all balances
                    float total = accumulate(accounts.begin(), accounts.end(), 0.0f, [](float accumulator, auto account) {
                        return accumulator + account.get_balance();
                        });

                    // Print total
                    std::cout << "Total in all accounts: $" << total << std::endl;

                    break;
                }
                // Add dividend (% of total)
                case 8:
                {
                    // Get percentage to add
                    std::cout << "Enter the dividend as a percentage: ";
                    float dividend = 0.0;
                    
                    // Validate user choice
                    bool valid = false;
                    while (!valid)
                    {
                        auto valid_tuple = valid_input<float>(std::cin);
                        valid = std::get<0>(valid_tuple);

                        if (valid)
                        {
                            dividend = std::get<1>(valid_tuple);
                            if (dividend <= 0)
                            {
                                valid = false;
                            }
                        }
                        if (!valid)
                        {
                            std::cout << "Invalid input. Please enter a positive, non-zero decimal number: ";
                        }
                    }

                    // Convert dividend to percentage
                    dividend = dividend / 100;

                    // Transform accounts to add dividend
                    auto accounts_end = std::transform(accounts.begin(), accounts.end(), accounts.begin(), [dividend](auto account) {
                        account.deposit(account.get_balance() * dividend);
                        return account;
                        });

                    // Remove untransformed accounts
                    accounts.erase(accounts_end, accounts.end());

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

template<typename T>
static std::tuple<bool, T> valid_input(std::istream& input)
{
    T value;

    if (!(input >> value))
    {
        input.clear(); // Reset the error flags
        input.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard bad input
        return std::make_tuple(false, T{});
    }

    return std::make_tuple(true, value);
}
