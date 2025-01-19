# include <iostream>
# include <string>
# include <sstream>
# include <vector>
# include "papo4ca.h"
using namespace std;

// проверка на то, является ли строка числом 
bool provero4ca(const string& str) {
    for (char a : str) {
        //проверка на то является ли символ цифрой 
        if (a < '0' || a > '9') {
            return false; // Если символ не цифра, говорим что не верно
        }
    }
    return true;
}

// преобразования строки в число (целое)
int strToInt(const string& str) {
    int result = 0;
    for (char a : str) {
        result = result * 10 + (a - '0'); // Преобразование символа в число с добавлением его в результат
    }
    return result;
}

// умножаем наибольшее число на x 
void delaidelai(vector<int>& num, int x) {
    int carry = 0; // для хранения переноса
    for (size_t i = 0; i < num.size(); ++i) {
        int product = num[i] * x + carry; // текущую цифру умножаем и добавляем перенос
        num[i] = product % 10;           // сохраняем меньшую цифру результата в текущую позицию
        carry = product / 10;               // остаток записываем в перенос
    }
    // Добавляем оставшийся перенос, если он есть
    while (carry > 0) {
        num.push_back(carry % 10);
        carry /= 10;
    }
}

// вычисляем факториал числа 
// результат в обратном порядкесохраняется как массив цифр 
vector<int> factorial(int n) {
    vector<int> result(1, 1); // начинаем с факториала 1, 
    for (int i = 2; i <= n; ++i) {
        delaidelai(result, i); // умножаем текущее значение на i
    }
    return result;
}

//вывод числа, хранящйся в векторе
void printNum(const vector<int>& num) {
    for (int i = num.size() - 1; i >= 0; --i) {
        cout << num[i];
    }
    cout << endl;
}

// умножаем два наибольших числа
string delaidelaiNum(const string& num1, const string& num2) {
    int len1 = num1.size(), len2 = num2.size();
    vector<int> result(len1 + len2, 0); // длина равна сумме длин чисел

    // умножаем каждую цифру числа n1 на каждую цифру числа n2
    for (int i = len1 - 1; i >= 0; --i) {
        for (int j = len2 - 1; j >= 0; --j) {
            int product = (num1[i] - '0') * (num2[j] - '0') + result[i + j + 1];
            result[i + j + 1] = product % 10; // сохраняем маленькую цифру
            result[i + j] += product / 10;    // добавление переноса
        }
    }

    // преобразование результата в строку
    string resultStr;
    bool leadingZero = true; // флаг для пропуска нулей

    for (int num : result)
    {
        if (num != 0 || !leadingZero) { // пропускаем нули
            resultStr += (num + '0');   // преобразование цифры в символ и добавляением
            leadingZero = false;       // после первой цифры выключаем флаг
        }

    }

    if (resultStr.empty())
    {
        return "0"; // строка пустая, значит "0"
    }
    return resultStr; // в другом случае возвращаем результат
}

// вычисляем факториал числа , используя метод Карацубы
// умножаем числа, разбивая их на пары
string factorialK(int n) {
    if (n == 1) return "1"; // случай для факториала 1

    // создаем список всех чисел от 1 до n в виде строк
    vector<string> numb;
    for (int i = 1; i <= n; ++i) {
        string numStr;
        int temp = i;
        while (temp > 0) {
            char digit = (temp % 10) + '0'; // получаем текущую цифру
            numStr = digit + numStr;       // добавляем её в начало строки
            temp /= 10;                    // убираем маленькую цифру
        }
        numb.push_back(numStr);
    }


    // объединяем числа попарно
    while (numb.size() > 1) {
        vector<string> newNumbers; // объединения чисел
        for (size_t i = 0; i < numb.size(); i += 2) {
            if (i + 1 < numb.size()) {
                // умножаем пары чисел
                newNumbers.push_back(delaidelaiNum(numb[i], numb[i + 1]));
            }
            else {
                // если число без пары, добавляем его в исходном виде
                newNumbers.push_back(numb[i]);
            }
        }
        numb = newNumbers; // объединение
    }
    return numb[0]; // позвращаем результат умножения
}

// преобразование из строки в число
int customstrToInt(const string& str)
{
    int result = 0;
    // проходимся посимвольно по строке.
    for (char c : str) {
        result = result * 10 + (c - '0'); // преобразуем символ в число
    }
    return result;
}
