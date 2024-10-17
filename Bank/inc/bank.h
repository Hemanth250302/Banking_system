#ifndef BANK_H
#define BANK_H

#include "account.h"

class Bank
{
    Account **accounts;
    int accountCount;
    int accountCapacity;

    void resizeAccountsArray();

public:
    Bank();
    Account *openAccount(std::string &firstName,std::string &lastName, std::string password, double initialBalance);
    Account *findAccount(long accountNumber);
    bool authenticateCustomer( std::string &firstName,std::string &lastName,std::string &password, long accountNumber);
    bool authenticateAdmin(const std::string &password);
    void displayBalance(long accountNumber);
    bool deposit(long accountNumber, double amount);
    bool withdraw(long accountNumber, double amount);
    void displayMiniStatement(long accountNumber);
    void displayBankStatement(long accountNumber);
    void closeAccount(long accountNumber);
    void displayAllAccounts();
    ~Bank();
};

#endif