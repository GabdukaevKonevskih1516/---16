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
    cout << "���������� ������ ������������, ������� �� ������ ������))) " << endl;
    cout << "���� �� ��� ������ ��� ��� - �� ������" << endl;
    cout << endl;
    cout << "��� ��������� �������� ���� ��� ����� ��������� (n!)!" << endl;
    cout << "������ ������ � ���� �� ������� ���� � ����� ��� ������������...(" << endl;
    cout << "����� n - ��� ����������� ������������� ����� � ��� ������ ���� > = 3" << endl;
    cout << endl;
    cout << "������� �������� ����� ������:" << endl;
    cout << endl;
    cout << "1 ��������� ��� ����� ����� ������� ������ ������ ������" << endl;
    cout << ".. ��� ���������, ���������� ��������� �����, ������� ���� �� ����, � � ������ ����������� ����������� ��� ������ � ������. " << endl;
    cout << ".. ���� ����������� �� ����� ������� 8! = 40320, ��������� ��� ����� ����� 40320! ( ��������� 1*2*3*4*...*40320 ) � � ����� � ��� ����� ����� 168 187 ����)" << endl;
    cout << endl;
    cout << "2 ���������� ������� ����������� ����� ������ ������ ����� �������" << endl;
    cout << endl;
    cout << "3 ���� ���������� ������ 15-20 �����, ������ ��������� ���������)" << endl;
    cout << endl;
    cout << "����� ���������� �������� ����� n � ��������� �������� (n!)! (���� ���� ����� ���������� ��� - ��, ���� ����������, ������� <3 )" << endl;

    int n;
    string input;

    bool validInput = false; // ���� ��� �������� ������������ �����

    while (!validInput) {
        cout << "������� ����� n (n >= 3): ";
        getline(cin, input);

        // �������� �� �� �������� �� ������ ���������� ������
        if (provero4ca(input)) {
            // �������������� ������ � �����
            n = strToInt(input);

            if (n >= 3) {
                validInput = true; // ������� ���������, ��������� ����
            }
            else {
                cout << "�������� �� ������ ��� ����� 3, ����� �����������!" << endl;
            }
        }
        else {
            cout << "�� ������ ��������, ����� ���� �������! (������ �������������!!!)" << endl;
        }
    }

    // ��������� ������ ��������� n!
    vector<int> firstFactorial = factorial(n);
    cout << "�������� n!: ";
    printNum(firstFactorial);

    // ������������� ���������� ������� ���������� � ������
    string factorialValueStr;
    for (int i = firstFactorial.size() - 1; i >= 0; --i) {
        factorialValueStr += (firstFactorial[i] + '0');
    }

    // ���� 2: ��������� ������� ��������� � �������������� ������ ��������
    cout << "(n!)! ���� ��� ����������� " << endl;
    int factorialAsInt = customstrToInt(factorialValueStr); // ����������� ������ � �����.
    string result = factorialK(factorialAsInt);
    cout << "�������� (n!)!: " << result << endl;
   
    return 0;
}