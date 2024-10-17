#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H

#include <string>

enum InputType
{
    Integer,
    Float
};

class InputValidation
{
public:
    bool validate();
    double inputValidator(InputType type);
    std::string trimSpaces(std::string &input);
    std::string inputValidatorString();
};

#endif