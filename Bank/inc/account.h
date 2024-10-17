#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

struct Transaction
{
    std::string type;
    double amount;
    double balance;

    void display();
};

class Account
{
    long accountNumber{};
    std::string firstName;
    std::string lastName;
    std::string password;
    double balance{};
    static long nextAccountNumber;
    Transaction *transactions;
    int transactionCount;
    int transactionCapacity;
    void resizeTransactionArray();

public:
    Account() = default;
    Account(std::string firstName,std::string lastName, std::string password, double initialBalance);
    long getAccountNumber();
    double getBalance();
    std::string getAccountHolderFirstName();
    std::string getAccountHolderLastName();
    bool checkPassword(std::string password);
    void deposit(double amount);
    bool withdraw(double amount);
    friend std::ostream& operator<<(std::ostream &out, Account &account);
    void displayMiniStatement();
    void displayBankStatement();
    ~Account();
};

#endif
