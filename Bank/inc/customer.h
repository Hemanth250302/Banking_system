#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "user.h"
#include "inputValidation.h"

class Customer : public User
{
private:
std::string lastName;
    long accountNumber;

public:
    Customer( std::string &firstName ,std::string &lastname, Bank *bank ,InputValidation *validator);
    bool authenticate();
    virtual void displayMenu() override;
    virtual void performOperations() override;
};

#endif
