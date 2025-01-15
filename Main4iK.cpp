#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "papo4ca.h" 
#include <windows.h>
 
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << endl;
    cout << "Здравствуй добрый пользователь, надеюсь ты правда добрый))) " << endl;
    cout << "Если ты тут значит это что - то значит" << endl;
    cout << endl;
    cout << "Эта программа вычислит тебе вот такой примерчик (n!)!" << endl;
    cout << "Честно говоря я тоже не понимаю кому и зачем это понадобилось...(" << endl;
    cout << "Число n - это обязательно положительное число и оно должно быть > = 3" << endl;
    cout << endl;
    cout << "Немного приколов перед вводом:" << endl;
    cout << endl;
    cout << "1 Факториал эта такая штука которая оочень быстро растет" << endl;
    cout << ".. Для понимания, представть маленькую волну, которая идет на тебя, и с каждой милисекндой становиться все больше и больше. " << endl;
    cout << ".. Если рассмотреть на числа обычный 8! = 40320, представь что нужно найти 40320! ( умножение 1*2*3*4*...*40320 ) и в итоге в это числе будет 168 187 цифр)" << endl;
    cout << endl;
    cout << "2 Вычисление больших факториалов может занять оочень много времени" << endl;
    cout << endl;
    cout << "3 Если вычисление больше 15-20 минут, можешь завершать программу)" << endl;
    cout << endl;
    cout << "Введи пожалуйста желаемое число n и программа вычеслит (n!)! (молю тебя введи адекватное что - то, буду благодарен, спасибо <3 )" << endl;

    int n;
    string input;

    bool validInput = false; // флаг для проверки правильности ввода

    while (!validInput) {
        cout << "Введите число n (n >= 3): ";
        getline(cin, input);

        // проверка на то является ли строка адекватным числом
        if (provero4ca(input)) {
            // преобразование строки в число
            n = strToInt(input);

            if (n >= 3) {
                validInput = true; // условия выполнены, завершаем цикл
            }
            else {
                cout << "Написано же больше или равно 3, читай внимательно!" << endl;
            }
        }
        else {
            cout << "Вы немого ошиблись, цыфры нада вводить! (только положительные!!!)" << endl;
        }
    }

    // вычисляем первый факториал n!
    vector<int> firstFactorial = factorial(n);
    cout << "Значение n!: ";
    printNum(firstFactorial);

    // преобрзование результата первого факториала в строку
    string factorialValueStr;
    for (int i = firstFactorial.size() - 1; i >= 0; --i) {
        factorialValueStr += (firstFactorial[i] + '0');
    }

    // Этап 2: вычисляем двойной факториал с использованием метода Карацубы
    cout << "(n!)! пока еще вычисляется " << endl;
    int factorialAsInt = customstrToInt(factorialValueStr); // преобразуем строки в цифры.
    string result = factorialK(factorialAsInt);
    cout << "Значение (n!)!: " << result << endl;
   
    return 0;
}