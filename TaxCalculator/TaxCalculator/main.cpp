#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <typeinfo>
#include <stdexcept>

uint32_t SalaryAfterTax(int BaseSalary)
{
    // Brackets and variables, can be tweaked.
    uint32_t    TopBracket{100000}, MiddleBracket{50000}, LowerBracket{13000};
    double      TopTax{0.55}, MiddleTax{0.45}, LowerTax{0.3};

    // Maths in the background
    double NewSalary{0};
    if (BaseSalary > TopBracket)
    {
        NewSalary += (1 - TopTax) * (BaseSalary - TopBracket);
        NewSalary += SalaryAfterTax(TopBracket);
    }
    else if (BaseSalary > MiddleBracket && BaseSalary <= TopBracket)
    {
        NewSalary += (1 - MiddleTax) * (BaseSalary - MiddleBracket);
        NewSalary += SalaryAfterTax(MiddleBracket);
    }
    else if (BaseSalary > LowerBracket && BaseSalary <= MiddleBracket)
    {
        NewSalary += (1 - LowerTax) * (BaseSalary - LowerBracket);
        NewSalary += SalaryAfterTax(LowerBracket);
    }
    else NewSalary += BaseSalary;

    return static_cast<uint32_t>(NewSalary);
}

int main()
{
    while (true)
    {
        try
        {
            std::cout << "\n\n\n----------------------------------------";
            std::cout << "\nEnter your salary: ";
            int salary; std::cin >> salary;

            if (std::cin.fail() || salary < 0)
            {
                throw std::invalid_argument("\nMust enter a positive integer... try again.");
            }
            else
            {
                std::cout << "\nSalary after tax: " << SalaryAfterTax(salary) << "\n----------------------------------------";
            } 
        }
        catch (std::invalid_argument& e)
        {
            std::cerr << e.what();
        }
    }

    return 0;
}