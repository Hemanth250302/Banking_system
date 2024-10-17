#include "user.h"
#include "bank.h"
User::User(std::string name, Bank *bank, InputValidation *validator) : bank(bank)
{
    this->validator=validator;
    this->name = name;
}
User::~User()
{
}
