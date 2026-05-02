// bank-system-2.cpp
#include "account.h"
#include <iostream>

int main()
{
    // Instantiate account
    Account account{};

    // Initialize account
    account.init_account();

    // Loop until user is done
    bool done = false;
    while (!done)
    {
        // Initialize user choiceand money handling
        int choice = 0;
        float amount = 0;

        // Display menu
        std::cout << "\nAccount Menu:\n"
            "0. Quit Program\n"
            "1. Display Account Information\n"
            "2. Add a deposit to an account\n"
            "3. Withdraw from an account\n"
            "Your choice : ";

        // Get user choice
        std::cin >> choice;

        // Handle user's choice
        switch (choice)
        {
            // Exit program
            case 0:
                done = true;
                break;
            // Display account information
            case 1:
                //account.display();
                //account.display(std::cout);
                std::cout << account;
                break;
            // Deposit money
            case 2:
                std::cout << "Amount to deposit: ";
                std::cin >> amount;
                account += amount;
                break;
            // Withdraw money
            case 3:
                std::cout << "Amount to withdraw: ";
                std::cin >> amount;
                account -= amount;
                break;
            // Default: quit
            default:
                done = true;
                break;
        }
    }

    return 0;
}
