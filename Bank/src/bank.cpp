#include "bank.h"

Bank::Bank()
{
    accountCount = 0;
    accountCapacity = 10;
    accounts = new Account *[accountCapacity];
}

void Bank::resizeAccountsArray()
{
    accountCapacity *= 2;
    Account **newAccountArray = new Account *[accountCapacity];
    for (int index = 0; index < accountCount; index++)
    {
        newAccountArray[index] = accounts[index];
    }
    delete[] accounts;
    accounts = newAccountArray;
}

Account *Bank::openAccount(std::string &firstName, std::string &lastName, std::string password, double initialBalance)
{
    if (accountCount == accountCapacity)
    {
        resizeAccountsArray();
    }
    accounts[accountCount] = new Account(firstName, lastName, password, initialBalance);
    return accounts[accountCount++];
}

Account *Bank::findAccount(long accountNumber)
{
    Account *account = nullptr;
    for (int index = 0; index < accountCount; index++)
    {
        if (accounts[index]->getAccountNumber() == accountNumber)
        {
            account = accounts[index];
        }
    }
    return account;
}

bool Bank::authenticateCustomer(std::string &name, std::string &lastName, std::string &password, long accountNumber)
{
    Account *account = findAccount(accountNumber);
    return (account && account->getAccountHolderFirstName() == name && 
    account->getAccountHolderLastName() == lastName && account->checkPassword(password));
}

bool Bank::authenticateAdmin(const std::string &password)
{
    return password == "admin123";
}

void Bank::displayBalance(long accountNumber)
{
    Account *account = findAccount(accountNumber);
    if (account)
    {
        std::cout << "Current Balance:";
        std::cout << account->getBalance() << std::endl;
    }
}

bool Bank::deposit(long accountNumber, double amount)
{
    bool depositStatus = false;
    Account *account = findAccount(accountNumber);
    if (account)
    {
        account->deposit(amount);
        depositStatus = true;
    }
    return depositStatus;
}

bool Bank::withdraw(long accountNumber, double amount)
{
    bool withdrawStatus = false;
    Account *account = findAccount(accountNumber);
    if (account)
    {
        withdrawStatus = account->withdraw(amount);
    }
    return withdrawStatus;
}

void Bank::closeAccount(long accountNumber)
{
    bool isAccountDeleted = false;
    for (int index = 0; index < accountCount; index++)
    {
        if (accounts[index]->getAccountNumber() == accountNumber)
        {
            for (int shiftIndex = index; shiftIndex < accountCount - 1; shiftIndex++)
            {
                accounts[shiftIndex] = accounts[shiftIndex + 1];
            }
            --accountCount;
            isAccountDeleted = true;
            std::cout << "Account closed sucessfully." << std::endl;
            break;
        }
    }
    if (!isAccountDeleted)
    {
        std::cout << "Account not found!!! deletion not possible." << std::endl;
    }
}

void Bank::displayMiniStatement(long accountNumber)
{
    Account *account = findAccount(accountNumber);
    if (account)
    {
        account->displayMiniStatement();
    }
    else
        std::cout << "account Not found!!!" << std::endl;
}

void Bank::displayBankStatement(long accountNumber)
{
    Account *account = findAccount(accountNumber);
    if (account)
    {
        account->displayBankStatement();
    }
    else
        std::cout << "account Not found!!!" << std::endl;
}

void Bank::displayAllAccounts()
{
    if (accountCount == 0)
    {
        std::cout << "No accounts to display." << std::endl;
        return;
    }

    for (int index = 0; index < accountCount; index++)
    {
        std::cout << *(accounts[index]) << std::endl;
    }
}

Bank::~Bank()
{
    for (int index = 0; index < accountCount; index++)
    {
        delete accounts[index];
    }
    delete[] accounts;
}