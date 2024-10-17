#include "account.h"

long Account::nextAccountNumber = 123456000;

void Transaction::display()
{
    std::cout << type << "         " << amount << "  " << balance << std::endl;
}

Account::Account(std::string fname, std::string lname, std::string password, double initialBalance)
{
    firstName = fname;
    lastName = lname;
    this->password = password;
    accountNumber = ++nextAccountNumber;
    balance = initialBalance;
    transactionCount = 0;
    transactionCapacity = 10;
    transactions = new Transaction[transactionCapacity];
}

long Account::getAccountNumber()
{
    return accountNumber;
}

double Account::getBalance()
{
    return balance;
}

std::string Account::getAccountHolderFirstName()
{
    return firstName;
}

std::string Account::getAccountHolderLastName()
{
    return lastName;
}

bool Account::checkPassword(std::string password)
{
    return this->password == password;
}

void Account::deposit(double amount)
{
    balance += amount;
    if (transactionCount == transactionCapacity)
    {
        resizeTransactionArray();
    }
    transactions[transactionCount++] = {"Deposit", amount, balance};
}

bool Account::withdraw(double amount)
{
    if (balance < amount)
        return false;
    balance -= amount;
    if (transactionCount == transactionCapacity)
    {
        resizeTransactionArray();
    }
    transactions[transactionCount++] = {"Withdraw", amount, balance};

    return true;
}

std::ostream &operator<<(std::ostream &out, Account &account)
{
    out << "AccountHolder name:" << account.getAccountHolderFirstName() << " " << account.getAccountHolderLastName() << std::endl;
    out << "Account Number:" << account.getAccountNumber() << std::endl;
    out << "Balance:" << account.getBalance() << std::endl;
    return out;
}

void Account::resizeTransactionArray()
{
    transactionCapacity *= 2;
    Transaction *newArray = new Transaction[transactionCapacity];
    for (int index = 0; index < transactionCount; index++)
    {
        newArray[index] = transactions[index];
    }
    delete[] transactions;
    transactions = newArray;
}

void Account::displayMiniStatement()
{
    std::cout << "Mini Bank Statement " << std::endl;
    std::cout << "Account Number: " << accountNumber << std::endl;
    std::cout << "Balance: " << balance << std::endl;
    std::cout << "Last 5 Transactions:" << std::endl;
    std::cout << "TransactionType" << "  " << "Amount" << " " << "Balance" << std::endl;
    if (transactionCount <= 5)
    {
        for (int index = 0; index < transactionCount; index++)
        {
            transactions[index].display();
        }
    }
    else
    {
        int startIndex = transactionCount - 5;
        for (int index = startIndex; index < transactionCount; index++)
        {
            transactions[index].display();
        }
    }
}

void Account::displayBankStatement()
{
    std::cout << "Bank Statement: " << std::endl;
    std::cout << "Account Number: " << accountNumber << std::endl;
    std::cout << "Balance: " << balance << std::endl;
    std::cout << "All Transactions:" << std::endl;
    std::cout << "TransactionType" << "  " << "Amount" << " " << "Balance" << std::endl;
    for (int index = 0; index < transactionCount; index++)
    {
        transactions[index].display();
    }
}

Account::~Account()
{
    delete[] transactions;
}