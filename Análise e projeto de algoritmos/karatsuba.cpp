#include <bits/stdc++.h>
using namespace std;
string sub_str(string str1, string str2)
{
    string resultado = "";
    int carry = 0;
    int n1 = str1.size();
    int n2 = str2.size();
    int n = max(n1, n2);
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    for (int i = 0; i < n; i++)
    {
        int digit1 = (i < n1) ? (str1[i] - '0') : 0;
        int digit2 = (i < n2) ? (str2[i] - '0') : 0;
        int diff = digit1 - digit2 - carry;
        if (diff < 0)
        {
            diff += 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        resultado.push_back(diff + '0');
    }
    while (resultado.length() > 1 && resultado.back() == '0')
    {
        resultado.pop_back();
    }
    reverse(resultado.begin(), resultado.end());
    return resultado;
}
string soma_str(string str1, string str2)
{
    string resultado = "";
    int carry = 0;
    int n1 = str1.size();
    int n2 = str2.size();
    int n = max(n1, n2);
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    for (int i = 0; i < n; i++)
    {
        int digit1 = (i < n1) ? (str1[i] - '0') : 0;
        int digit2 = (i < n2) ? (str2[i] - '0') : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        resultado.push_back((sum % 10) + '0');
    }
    if (carry)
        resultado.push_back(carry + '0');
    reverse(resultado.begin(), resultado.end());
    return resultado;
}
int main()
{
    string num1;
    string num2;
    cin >> num1 >> num2;
    string resultado = soma_str(num1, num2);
    string resultado1 = sub_str(num1, num2);
    cout << "String 1: \"" << num1 << "\"" << endl;
    cout << "String 2: \"" << num2 << "\"" << endl;
    cout << "Resultado da soma numérica: " << resultado << endl;
    cout << "Resultado da subtracao numérica: " << resultado1 << endl;
    return 0;
}