#include "admin.h"
#include "bank.h"
#include "inputValidation.h"
#include <iostream>

Admin::Admin(const std::string &name, Bank *bank, InputValidation *validator)
    : User(name, bank, validator)
{
}

void Admin::displayMenu()
{
    std::cout << "\n Admin Menu" << std::endl;
    std::cout << "1. Open Account" << std::endl;
    std::cout << "2. Close Account" << std::endl;
    std::cout << "3. Display All Account" << std::endl;
    std::cout << "4. Return to main menu" << std::endl;
    std::cout << "Enter your Choice" << std::endl;
}

void Admin::performOperations()
{
    int choice;
    std::string firstName, lastName, password;
    double initialBalance;
    long accountNumber;

    do
    {
        displayMenu();
        choice = validator->inputValidator(Integer);

        switch (choice)
        {
        case 1:
            std::cout << "Enter Account Holder First Name:";
            firstName = validator->inputValidatorString();
            std::cout << "Enter Account Holder Last Name:";
            lastName = validator->inputValidatorString();
            std::cout << "Enter password for the account:";
            password = validator->inputValidatorString();
            std::cout << "Enter Initial Balance: ";
            initialBalance = validator->inputValidator(Float);
            bank->openAccount(firstName, lastName, password, initialBalance);
            break;

        case 2:
            std::cout << "Enter Account Number to Close: ";
            accountNumber = validator->inputValidator(Integer);
            bank->closeAccount(accountNumber);
            break;

        case 3:
            bank->displayAllAccounts();
            break;

        case 4:
            std::cout << "returning to Main Menu.." << std::endl;
            break;
        default:
            std::cout << "Invalid choice!!! please try again..." << std::endl;
            break;
        }

    } while (choice != 4);
}

Admin::~Admin() = default;