#include <iostream>


class Calculator
{
private:

    double num1 = 0;
    double num2 = 0;

public:

    double add()
    {
        return num1 + num2;
    }

    double multiply()
    {
        return num1 * num2;
    }

    double subtract_1_2()
    {
        return num1 - num2;
    }

    double subtract_2_1()
    {
        return num2 - num1;
    }

    double divide_1_2()
    {
        return num1 / num2;
    }

    double divide_2_1()
    {
        return num2 / num1;
    }

    bool set_num1(double num1)
    {
        if (num1 == 0)
        {
            return false;
        }
        else
        {
            this->num1 = num1;

            return true;
        }
    }

    bool set_num2(double num2)
    {
        if (num2 == 0)
        {
            return false;
        }
        else
        {
            this->num2 = num2;

            return true;
        }
    }
};


void set_num1(Calculator* calc)
{
    std::cout << "Введите num1: ";
    int num1 = 0;
    std::cin >> num1;
    if (!calc->set_num1(num1))
    {
        std::cout << "Неверный ввод!" << std::endl;

        set_num1(calc);
    }
}


void set_num2(Calculator* calc)
{
    std::cout << "Введите num2: ";
    int num2 = 0;
    std::cin >> num2;
    if (!calc->set_num2(num2))
    {
        std::cout << "Неверный ввод!" << std::endl;

        set_num2(calc);
    }
}


void print_results(Calculator* calc)
{
    std::cout << "num1 + num2 = " << calc->add() << std::endl;
    std::cout << "num1 * num2 = " << calc->multiply() << std::endl;
    std::cout << "num1 - num2 = " << calc->subtract_1_2() << std::endl;
    std::cout << "num2 - num1 = " << calc->subtract_2_1() << std::endl;
    std::cout << "num1 / num2 = " << calc->divide_1_2() << std::endl;
    std::cout << "num2 / num1 = " << calc->divide_2_1() << std::endl;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");


    Calculator calc;

    bool endOfProg = false;
    do {
        set_num1(&calc);
        set_num2(&calc);
        print_results(&calc);

        std::cout << "Продолжить выполнение программы? (y/n): ";
        char answer;
        std::cin >> answer;

        switch (answer)
        {
        case('Y'):
        case('y'):

            endOfProg = false;
            break;

        case('N'):
        case('n'):

            endOfProg = true;
            break;

        default:

            std::cout << "Сочтем это за 'нет'";
            endOfProg = true;
        }
    } while (!endOfProg);
}