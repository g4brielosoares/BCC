#include <bits/stdc++.h>
using namespace std;

// time ./multiplicacao < dados/10.txt > SaidaDadosMultiplicacao/10.txt

// diff SaidaDadosMultiplicacao/10.txt SaidaDados/out_10.txt

/*
    10 = {
        time ./multiplicacao < dados/10.txt > SaidaDadosMultiplicacao/10.txt

        real    0m0.004s
        user    0m0.002s
        sys     0m0.002s

        diff SaidaDadosMultiplicacao/10.txt SaidaDados/out_10.txt = { sem diferenças }
    }

    100 = {
        time ./multiplicacao < dados/100.txt > SaidaDadosMultiplicacao/100.txt

        real    0m0.005s
        user    0m0.002s
        sys     0m0.003s

        diff SaidaDadosMultiplicacao/100.txt SaidaDados/out_100.txt = { sem diferenças }
    }
    
    1000 = {
        time ./multiplicacao < dados/1000.txt > SaidaDadosMultiplicacao/1000.txt

        real    0m0.020s
        user    0m0.017s
        sys     0m0.003s

        diff SaidaDadosMultiplicacao/1000.txt SaidaDados/out_1000.txt = { sem diferenças }
    }

    10000 = {
        time ./multiplicacao < dados/10000.txt > SaidaDadosMultiplicacao/10000.txt

        real    0m1.469s
        user    0m1.467s
        sys     0m0.002s

        diff SaidaDadosMultiplicacao/10000.txt SaidaDados/out_10000.txt = { sem diferenças }
    }

    100000 = {
        
    }
*/

string soma_str(string str1, string str2);
string sub_str(string str1, string str2);

string remover_zeros(string s) {
    while (s.size() > 1 && s[0] == '0') s.erase(s.begin());
    return s;
}

string multiply_standard(string a, string b) {
    a = remover_zeros(a);
    b = remover_zeros(b);

    if (a == "0" || b == "0") return "0";

    int n = a.size(), m = b.size();
    vector<int> res(n + m, 0);

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i + j] += (a[i] - '0') * (b[j] - '0');
            if (res[i + j] >= 10) {
                res[i + j + 1] += res[i + j] / 10;
                res[i + j] %= 10;
            }
        }
    }

    while (res.size() > 1 && res.back() == 0) res.pop_back();

    string s;
    for (int i = res.size() - 1; i >= 0; i--)
        s.push_back(res[i] + '0');

    return s;
}

string sub_str(string str1, string str2) {
    string resultado = "";
    int carry = 0;
    int n1 = str1.size();
    int n2 = str2.size();
    int n = max(n1, n2);
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    for (int i = 0; i < n; i++) {
        int digit1 = (i < n1) ? (str1[i] - '0') : 0;
        int digit2 = (i < n2) ? (str2[i] - '0') : 0;
        int diff = digit1 - digit2 - carry;
        if (diff < 0) {
            diff += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        resultado.push_back(diff + '0');
    }
    while (resultado.length() > 1 && resultado.back() == '0') {
        resultado.pop_back();
    }
    reverse(resultado.begin(), resultado.end());
    return resultado;
}

string soma_str(string str1, string str2) {
    string resultado = "";
    int carry = 0;
    int n1 = str1.size();
    int n2 = str2.size();
    int n = max(n1, n2);
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    for (int i = 0; i < n; i++) {
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    cout << multiply_standard(a, b) << "\n";
    return 0;
}