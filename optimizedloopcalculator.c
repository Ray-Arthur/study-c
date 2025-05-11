#include <stdio.h>

float add(float number1, float number2) // simple addtion function
{
    float result = number1 + number2;
    return result;
}

float subtract(float minuend, float subtrahend) // simple subtraction function
{
    float result = minuend - subtrahend;
    return result;
}

float multiply(float number1, float number2) // simple multiplication function
{
    float result = number1 * number2;
    return result;
}

float divide(float dividend, float divisor) // simple division function
{
    float result = dividend / divisor;
    return result;
}

float power(float base, int exponent) // simple power function, can't handle non-integers exponents
{
    float result = 1;
    int isnegative = 0;
    if (exponent == 0) // handle exponent equal to 0
    {
        return result = 1;
    }
    if (exponent < 0) // handle negative integers exponents
    {
        isnegative = 1;
        exponent = -exponent;
    }
    while (exponent > 0)
    {
        result *= base;
        exponent--;
    }
    if (isnegative == 1) // handle negative integers exponents
    {
        result = 1 / result;
    }
    return result;
}

void clear_buffer() // function to clear unwanted keyboar buffer
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

void print_menu() // function to print the main menu
{
    printf("+--------------------------------+\n");
    printf("| Choose one operation:           |\n");
    printf("+--------------------------------+\n");
    printf("| 1 - Addition                   |\n");
    printf("| 2 - Subtraction                |\n");
    printf("| 3 - Multiplication             |\n");
    printf("| 4 - Division                   |\n");
    printf("| 5 - Power                      |\n");
    printf("| 6 - Exit                       |\n");
    printf("+--------------------------------+\n");
}

int get_menu_option(const char *prompt, int min, int max) // function to handle the menu selection
{
    int choice;
    int input_status;

    while (1)
    {
        printf("%s", prompt);
        input_status = scanf("%d", &choice);

        if (input_status == 1)
        {
            clear_buffer();

            if (choice >= min && choice <= max)
            {
                return choice;
            }
            else
            {
                printf("ERROR!!! Select an option between %d to %d!\n", min, max);
            }
        }
        else
        {
            printf("ERROR!!! Please enter a valid number!\n");
            clear_buffer();
        }
    }
}

int get_int(const char *prompt) // function to handle integers inputs
{
    int number;
    int input_status;

    while (1)
    {
        printf("%s", prompt);
        input_status = scanf("%d", &number);

        if (input_status == 1)
        {
            clear_buffer();
            return number;
        }
        else
        {
            printf("ERROR!!! Please enter a valid number!\n");
            clear_buffer();
        }
    }
}

float get_float(const char *prompt) // function to handle float values filtering unwanted input
{
    float number;
    float input_stts;

    while (1)
    {
        printf("%s", prompt);
        input_stts = scanf("%f", &number);

        if (input_stts == 1)
        {
            clear_buffer();
            return number;
        }
        else
        {
            printf("ERROR!!! Please enter a valid number!\n");
            clear_buffer();
        }
    }
}

int main() // main function of the calculator with a loop to maintain the things going until the user says otherwise

{
    int operationchoice;
    do
    {
        print_menu();
        operationchoice = get_menu_option("Type an option:\n", 1, 6);

        switch (operationchoice)
        {
            case 1: // addition case
            {
                printf("\nStarting Addition with two numbers...\n");
                float number1 = get_float("Type the first number:\n");
                float number2 = get_float("Type the second number:\n");
                float result = add(number1, number2);
                printf("The result is %.4f\n", result);
                break;
            }

            case 2: // subtraction case
            {
                printf("\nStarting Subtraction with two numbers...\n");
                float minuend = get_float("Type the minuend:\n");
                float subtrahend = get_float("Type the subtrahend:\n");
                float result = subtract(minuend, subtrahend);
                printf("The result is %.4f\n", result);
                break;
            }

            case 3: // multiplication case
            {
                printf("\nStarting Multiplication with two numbers...\n");
                float number1 = get_float("Type the first number:\n");
                float number2 = get_float("Type the second number:\n");
                float result = multiply(number1, number2);
                printf("The result is %.4f\n", result);
                break;
            }

            case 4: // division case
            {
                printf("\nStarting Division with two numbers...\n");
                float dividend = get_float("Type the dividend:\n");
                float divisor = get_float("Type the divisor:\n");
                while (divisor == 0)
                {
                    printf("ERROR!!! The divisor can not be zero\n");
                    divisor = get_float("Type the divisor:\n");
                }
                float result = divide(dividend, divisor);
                printf("The result is %.4f\n", result);
                break;
            }

            case 5: // power case
            {
                printf("\nStarting Power Operation with two numbers...\n");
                float base = get_float("Type the base:\n");
                int exponent = get_int("Type the exponent(integer):\n");
                float result = power(base, exponent);
                printf("The result is %.4f\n", result);
                break;
            }
            case 6: // exit case
            {
                printf("Exiting executable...\n");
                break;
            }
            default: // debug
                printf("ERROR!!! Unknow error detected...\n");
        }
    }
    while (operationchoice <= 5 && operationchoice >= 1);
    return 0;
}
