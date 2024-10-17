#ifndef USER_H
#define USER_H

#include "inputValidation.h"
#include <string>

class Bank;

class User
{
protected:
    std::string name;
    Bank *bank;
    InputValidation *validator;

public:
    User(std::string name, Bank *bank, InputValidation *validator);
    virtual void displayMenu() = 0;
    virtual void performOperations() = 0;
    virtual ~User();
};

#endif