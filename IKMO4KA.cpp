# include <iostream>
# include <string>
# include <sstream>
# include <vector>
# include "papo4ca.h"
using namespace std;

// �������� �� ��, �������� �� ������ ������ 
bool provero4ca(const string& str) {
    for (char a : str) {
        //�������� �� �� �������� �� ������ ������ 
        if (a < '0' || a > '9') {
            return false; // ���� ������ �� �����, ������� ��� �� �����
        }
    }
    return true;
}

// �������������� ������ � ����� (�����)
int strToInt(const string& str) {
    int result = 0;
    for (char a : str) {
        result = result * 10 + (a - '0'); // �������������� ������� � ����� � ����������� ��� � ���������
    }
    return result;
}

// �������� ���������� ����� �� x 
void delaidelai(vector<int>& num, int x) {
    int carry = 0; // ��� �������� ��������
    for (size_t i = 0; i < num.size(); ++i) {
        int product = num[i] * x + carry; // ������� ����� �������� � ��������� �������
        num[i] = product % 10;           // ��������� ������� ����� ���������� � ������� �������
        carry = product / 10;               // ������� ���������� � �������
    }
    // ��������� ���������� �������, ���� �� ����
    while (carry > 0) {
        num.push_back(carry % 10);
        carry /= 10;
    }
}

// ��������� ��������� ����� 
// ��������� � �������� ������������������ ��� ������ ���� 
vector<int> factorial(int n) {
    vector<int> result(1, 1); // �������� � ���������� 1, 
    for (int i = 2; i <= n; ++i) {
        delaidelai(result, i); // �������� ������� �������� �� i
    }
    return result;
}

//����� �����, ��������� � �������
void printNum(const vector<int>& num) {
    for (int i = num.size() - 1; i >= 0; --i) {
        cout << num[i];
    }
    cout << endl;
}

// �������� ��� ���������� �����
string delaidelaiNum(const string& num1, const string& num2) {
    int len1 = num1.size(), len2 = num2.size();
    vector<int> result(len1 + len2, 0); // ����� ����� ����� ���� �����

    // �������� ������ ����� ����� n1 �� ������ ����� ����� n2
    for (int i = len1 - 1; i >= 0; --i) {
        for (int j = len2 - 1; j >= 0; --j) {
            int product = (num1[i] - '0') * (num2[j] - '0') + result[i + j + 1];
            result[i + j + 1] = product % 10; // ��������� ��������� �����
            result[i + j] += product / 10;    // ���������� ��������
        }
    }

    // �������������� ���������� � ������
    string resultStr;
    bool leadingZero = true; // ���� ��� �������� �����

    for (int num : result)
    {
        if (num != 0 || !leadingZero) { // ���������� ����
            resultStr += (num + '0');   // �������������� ����� � ������ � ������������
            leadingZero = false;       // ����� ������ ����� ��������� ����
        }

    }

    if (resultStr.empty())
    {
        return "0"; // ������ ������, ������ "0"
    }
    return resultStr; // � ������ ������ ���������� ���������
}

// ��������� ��������� ����� , ��������� ����� ��������
// �������� �����, �������� �� �� ����
string factorialK(int n) {
    if (n == 1) return "1"; // ������ ��� ���������� 1

    // ������� ������ ���� ����� �� 1 �� n � ���� �����
    vector<string> numb;
    for (int i = 1; i <= n; ++i) {
        string numStr;
        int temp = i;
        while (temp > 0) {
            char digit = (temp % 10) + '0'; // �������� ������� �����
            numStr = digit + numStr;       // ��������� � � ������ ������
            temp /= 10;                    // ������� ��������� �����
        }
        numb.push_back(numStr);
    }


    // ���������� ����� �������
    while (numb.size() > 1) {
        vector<string> newNumbers; // ����������� �����
        for (size_t i = 0; i < numb.size(); i += 2) {
            if (i + 1 < numb.size()) {
                // �������� ���� �����
                newNumbers.push_back(delaidelaiNum(numb[i], numb[i + 1]));
            }
            else {
                // ���� ����� ��� ����, ��������� ��� � �������� ����
                newNumbers.push_back(numb[i]);
            }
        }
        numb = newNumbers; // �����������
    }
    return numb[0]; // ���������� ��������� ���������
}

// �������������� �� ������ � �����
int customstrToInt(const string& str)
{
    int result = 0;
    // ���������� ����������� �� ������.
    for (char c : str) {
        result = result * 10 + (c - '0'); // ����������� ������ � �����
    }
    return result;
}