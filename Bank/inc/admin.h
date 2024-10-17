#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"

class Admin : public User
{
public:
    Admin(const std::string &name, Bank *bank, InputValidation *validator);
    void displayMenu() override;
    void performOperations() override;
    ~Admin();
};

#endif