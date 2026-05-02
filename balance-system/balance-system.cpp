// balance-system.cpp

#include <iostream>
#include <string>
#include <format>

// So I don't have to keep typing std::
using namespace std;

int main()
{
    int id_num = 0;
    string name = "";
    float balance = 0;

    // Get name
    cout << "Enter the name: ";
    getline(cin, name);

    // Get balance
    cout << "Enter the balance: ";
    cin >> balance;

    // Loop until user is done
    bool done = false;
    while (!done)
    {
        // Initialize user choice and money handling
        int choice = 0;
        float amount = 0;

        // Display menu
        cout << "\nAccount Menu:\n"
            "0. Quit Program\n"
            "1. Display Account Information\n"
            "2. Add a deposit to an account\n"
            "3. Withdraw from an account\n"
            "Your choice : ";

        // Get user choice
        cin >> choice;

        // Handle user's choice
        switch (choice)
        {
            // Exit program
            case 0:
                done = true;
                break;
            // Display account information
            case 1:
                cout << "Account ID: " << id_num << "  Name: " << name << "  Balance: $" << format("{:.2f}", balance) << endl;
                break;
            // Deposit money
            case 2:
                cout << "Amount to deposit: ";
                cin >> amount;
                balance += amount;
                break;
            // Withdraw money
            case 3:
                cout << "Amount to withdraw: ";
                cin >> amount;
                balance -= amount;
                break;
            // Default: quit
            default:
                done = true;
                break;
        }

    }

    return 0;
}