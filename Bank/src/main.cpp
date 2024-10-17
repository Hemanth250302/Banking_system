#include <iostream>
#include "bank.h"
#include "admin.h"
#include "customer.h"
#include "inputValidation.h"

int main()
{
    Bank bank;
    InputValidation validator;
    int choice;

    do
    {
        std::cout << "\nMain Menu\n";
        std::cout << "1. Admin Login\n";
        std::cout << "2. Customer Login\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        choice = validator.inputValidator(Integer);
        switch (choice)
        {
        case 1:
        {
            std::string adminPassword;
            std::cout << "Enter Admin Password: ";
            std::cin >> adminPassword;

            if (bank.authenticateAdmin(adminPassword))
            {
                Admin admin("Administrator", &bank, &validator);
                admin.performOperations();
            }
            else
            {
                std::cout << "Invalid Admin Password!\n";
            }
            break;
        }
        case 2:
        {
            std::string customerFirstName, customerLastName;
            std::cout << "Enter Customer  First Name: ";
            customerFirstName = validator.inputValidatorString();
            std::cout << "Enter Customer  Last Name: ";
            customerLastName = validator.inputValidatorString();
            Customer customer(customerFirstName, customerLastName, &bank, &validator);
            customer.performOperations();
            break;
        }
        case 3:
            std::cout << "Exiting...\n";
            break;

        default:
            std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
