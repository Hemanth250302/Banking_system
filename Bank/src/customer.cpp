#include "customer.h"
#include "bank.h"
#include "inputValidation.h"
#include <iostream>

Customer::Customer(std::string &firstName, std::string &lastname, Bank *bank, InputValidation *validator)
    : User(firstName, bank, validator)
{
    lastName = lastname;
}

bool Customer::authenticate()
{
    std::string password;
    std::cout << "Enter your account number: ";
    accountNumber = validator->inputValidator(Integer);
    std::cout << "Enter your password: ";
    password = validator->inputValidatorString();
    return bank->authenticateCustomer(name, lastName, password, accountNumber);
}

void Customer::displayMenu()
{
    std::cout << "\nCustomer Menu" << std::endl;
    std::cout << "1. Deposit" << std::endl;
    std::cout << "2. Withdraw" << std::endl;
    std::cout << "3. Check Balance" << std::endl;
    std::cout << "4.Display Statement" << std::endl;
    std::cout << "5.Display Mini Statement" << std::endl;
    std::cout << "6. Back to Main Menu" << std::endl;
    std::cout << "Enter your choice:" << std::endl;
}

void Customer::performOperations()
{
    int choice;
    double amount;
    if (!authenticate())
    {
        std::cout << "Authentication failed!\n";
        return;
    }
    do
    {
        {
            displayMenu();

            choice = validator->inputValidator(Integer);

            switch (choice)
            {

            case 1:
                std::cout << "Enter amount to deposit: ";
                amount = validator->inputValidator(Float);
                if (bank->deposit(accountNumber, amount))
                {
                    std::cout << "Deposit successful!\n";
                }
                else
                {
                    std::cout << "Deposit failed!\n";
                }
                break;
            case 2:
                std::cout << "Enter amount to withdraw: ";
                amount = validator->inputValidator(Float);
                if (bank->withdraw(accountNumber, amount))
                {
                    std::cout << "Withdrawal successful!\n";
                }
                else
                {
                    std::cout << "Insufficient funds!\n";
                }
                break;
            case 3:
                bank->displayBalance(accountNumber);
                break;
            case 4:
                bank->displayMiniStatement(accountNumber);
                break;
            case 5:
                bank->displayBankStatement(accountNumber);
                break;
            case 6:
                std::cout << "Returning to Main Menu.\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
            }
        }

    } while (choice != 6);
}
