#include <iostream>


class Counter
{
private:

    int value = 0;

public:

    Counter()
    {
        std::cout << "Вы желаете ввести начальное значение счетчика? (y/n)" << std::endl;
        char answer;
        std::cin >> answer;

        switch (answer)
        {
        case('Y'):
        case('y'):
            std::cout << "Введите значение, которое хотите установить: ";
            std::cin >> value;
            std::cout << std::endl;
            break;

        case('N'):
        case('n'):
            std::cout << "Будет использовано значение по умолчанию(1)\n" << std::endl;
            value = 1;
            break;

        default:
            std::cout << "Так как ответ не был распознан, будет использовано значение по умолчанию(1)\n" << std::endl;
            value = 1;
        }
    }

    void add()
    {
        ++value;
    }

    void subtract()
    {
        --value;
    }

    int getValue()
    {
        return value;
    }
};


int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");

    
    Counter counter;
    char answer;
    do
    {
        std::cout << "Введите команду (+, -, = или x): ";
        std::cin >> answer;

        switch (answer)
        {
        case('+'):
            counter.add();
            break;

        case('-'):
            counter.subtract();
            break;

        case('='):
            std::cout << counter.getValue() << std::endl;
            break;

        case('x'):
            std::cout << "Завершение работы программы!" << std::endl;
            break;

        default:
            std::cout << "Введена некорректная команда!";
        }
    } while (answer != 'x');
}