#include <iostream>
#include <limits>
#include "inputValidation.h"

bool InputValidation::validate()
{
    if (std::cin.fail())
    {
        std::cout << "Invalid input !!! Please enter again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    if (std::cin.peek() != '\n')
    {
        std::cout << "Extra characters detected! Please enter a valid input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

double InputValidation::inputValidator(InputType type)
{
    double validInput;
    while (true)
    {
        if (type == Integer)
        {
            int input;
            std::cin >> input;

            if (!validate())
            {
                continue;
            }

            if (input < 0)
            {
                std::cout << "Invalid input! Please enter a positive integer.\n";
                continue;
            }

            validInput = input;
            break;
        }
        else if (type == Float)
        {
            float input;
            std::cin >> input;

            if (!validate())
            {
                continue;
            }

            if (input < 0)
            {
                std::cout << "Invalid input! Please enter a positive number.\n";
                continue;
            }

            validInput = input;
            break;
        }
    }
    std::cin.ignore(10000, '\n');
    return validInput;
}

std::string InputValidation::trimSpaces(std::string &input)
{
    int length = input.size();
    int start = 0;
    while (start < length && isspace(input[start]))
        start++;
    int end = length - 1;
    while (end > start && isspace(input[end]))
        end--;
    return input.substr(start, end - start + 1);
}

std::string InputValidation::inputValidatorString()
{
    std::string input;
    while (true)
    {
        std::getline(std::cin, input);
        input = trimSpaces(input);
        if (input.empty())
        {
            std::cout << "Input must not be empty. Please enter again.\n";
            continue;
        }
        bool valid = true;
        for (char c : input)
        {
            if (!std::isalpha(c))
            {
                valid = false;
                break;
            }
        }

        if (valid)
        {
            break;
        }
        else
        {
            std::cout << "Input must contain only alphabets. Please enter again.\n";
        }
    }
    return input;
}